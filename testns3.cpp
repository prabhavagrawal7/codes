#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/internet-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/applications-module.h"
#include "ns3/netanim-module.h"
using namespace ns3;

NS_LOG_COMPONENT_DEFINE("FirstScriptExample");

int main (int argc, char *argv[])
{
CommandLine cmd;
cmd.Parse (argc, argv);

Time::SetResolution (Time::NS);
LogComponentEnable ("UdpEchoClientApplication", LOG_LEVEL_INFO);
LogComponentEnable ("UdpEchoServerApplication", LOG_LEVEL_INFO);

NodeContainer nodes;
nodes.Create (3);

PointToPointHelper pointToPoint;
pointToPoint.SetDeviceAttribute ("DataRate", StringValue ("5Mbps"));
pointToPoint.SetChannelAttribute ("Delay", StringValue ("2ms"));

NetDeviceContainer devices;
devices = pointToPoint.Install (nodes.Get (0), nodes.Get (1));
NetDeviceContainer devices1;
devices1 = pointToPoint.Install (nodes.Get (2), nodes.Get (1));

InternetStackHelper stack;
stack.Install (nodes);

Ipv4AddressHelper address;
address.SetBase ("10.1.1.0", "255.255.255.0");
Ipv4AddressHelper address1;
address1.SetBase ("198.168.1.0", "255.255.255.0");

Ipv4InterfaceContainer interfaces = address.Assign (devices);
Ipv4InterfaceContainer interfaces1 = address.Assign (devices1);

UdpEchoServerHelper echoServer (90) ;
UdpEchoServerHelper echoServer1 (91) ;

ApplicationContainer serverApps = echoServer.Install (nodes.Get (1));
serverApps.Start (Seconds (1.0));
serverApps.Stop (Seconds (10.0));

UdpEchoClientHelper echoClient (interfaces.GetAddress (1), 90);
echoClient.SetAttribute ("MaxPackets", UintegerValue (1)) ;
echoClient.SetAttribute ("Interval", TimeValue (Seconds (1.0)));
echoClient.SetAttribute ("PacketSize", UintegerValue (1024)) ;

UdpEchoClientHelper echoClient1 (interfaces.GetAddress (1), 91);
echoClient.SetAttribute ("MaxPackets", UintegerValue (1)) ;
echoClient.SetAttribute ("Interval", TimeValue (Seconds (1.0)));
echoClient.SetAttribute ("PacketSize", UintegerValue (1024)) ;

ApplicationContainer clientApps = echoClient.Install (nodes.Get (0));
clientApps.Start (Seconds (2.0));
clientApps.Stop (Seconds (6.0));

ApplicationContainer clientApps1 = echoClient1.Install (nodes.Get (2));
clientApps.Start (Seconds (2.0));
clientApps.Stop (Seconds (10.0));

AnimationInterface anim ("anim1.xml");
anim.SetConstantPosition(nodes.Get(0), 1.0, 2.0);
anim.SetConstantPosition(nodes.Get(1), 2.0, 3.0);
anim.SetConstantPosition(nodes.Get(2), 3.0, 4.0);

Simulator::Run ();
Simulator::Destroy ();

return 0;
}