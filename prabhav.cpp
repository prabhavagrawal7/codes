#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
#define order(a, b, c) ((a <= b) && (b <= c))
#define all(x) x.begin(), x.end()
#define tr(a, i) for (auto i : a)
#define f(i, n) for (ll i = 0; i < n; i++)

int c, p, current_time = 0;

// map from string to ll
map<string, vi> available_skills; // levels;

map<string, ll> max_skill_level;

struct Contributor
{
    string name;
    map<string, ll> skill;
    ll free_after = 0;
};
struct Project
{
    string name;
    ll duration, score, ending_time;
    vector<pair<string, ll>> req_skill;
    map<string, ll> m_req_skill;
    long double priority;
};
struct answer
{
    string name;
    vector<string> members;
};
vector<answer> ans;

vector<Contributor> contributers;
vector<Project> projects;
bool op(Project &a, Project &b)
{
    return (a.priority > b.priority);
    ;
}
long double TLD(ll n)
{
    return n;
}
void input()
{
    cin >> c >> p;
    
    for (int i = 0; i < c; i++)
    {
        Contributor temp_contributor;
        cin >> temp_contributor.name;

        ll skill_level, skills;
        string skill_name;

        cin >> skills;
        for (int j = 0; j < skills; j++)
        {
            cin >> skill_name >> skill_level;
            temp_contributor.skill[skill_name] = skill_level;
            max_skill_level[skill_name] = max(max_skill_level[skill_name], skill_level);
        }
        contributers.push_back(temp_contributor);
    }
    //
    for (int i = 0; i < p; i++)
    {
        Project temp_project;
        ll no_of_roles;
        cin >> temp_project.name >> temp_project.duration >>
            temp_project.score >> temp_project.ending_time >> no_of_roles;
        for (ll j = 0; j < no_of_roles; j++)
        {
            string req_skill_name;
            ll req_skill_lvl;
            cin >> req_skill_name >> req_skill_lvl;
            // cin >> temp_project.req_skill.second;
            temp_project.req_skill.push_back({req_skill_name, req_skill_lvl});
            temp_project.m_req_skill[req_skill_name] = req_skill_lvl;
        }
        temp_project.priority = TLD(temp_project.score) / TLD(temp_project.m_req_skill.size());
        projects.push_back(temp_project);
    }
}

void execute_project(Project p)
{
    // fetch skillset needed for p
    // c++, java
    // find best available guy for c++
    // mark him unavailable till currenttime+duration
    // find best guy for java
    // mark him unavailable till currenttime+duration
    // skill.second -> skill level
    answer temp_ans;
    vector<Contributor> project_contributors;

    ll temp_score = p.score;

    if (current_time + p.duration > p.ending_time)
        temp_score -= current_time + p.duration - p.ending_time;

    if (temp_score <= 0)
        return;

    for (auto &skill : p.req_skill)
    {
        bool found = 0;
        for (auto &person : contributers)
        {
            if (person.free_after <= current_time && person.skill[skill.first] >= skill.second)
            {
                person.free_after = current_time + p.duration;
                found = 1;
                project_contributors.push_back(person);
                break;
            }
        }
        if (found == 0)
        {
            for (auto &person : contributers)
            {
                person.free_after -= p.duration;
            }
            return;
        }
    }
    temp_ans.name = p.name;
    for (auto &contributor : project_contributors)
    {
        temp_ans.members.push_back(contributor.name);
    }
    ans.push_back(temp_ans);
    current_time += p.duration;
}

int main()
{
    freopen("d_input.txt", "r", stdin);
    freopen("d_output.txt", "w", stdout);
    input();
    sort(projects.begin(), projects.end(), op);
    for (int i = 0; i < p; i++)
    {
        execute_project(projects[i]);
    }
    cout << ans.size() << endl;
    for (auto c1 : ans)
    {
        cout << c1.name << endl;
        for (auto c2 : c1.members)
        {
            cout << c2 << " ";
        }
        cout << endl;
    }
    return 0;
}

/*
command to run
cd "/home/prabhavagrawal7/codes/" && g++ hashcode.cpp -o hashcode && "/home/prabhavagrawal7/codes/"hashcode
*/