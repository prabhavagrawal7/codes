# General Instruction For LLM

Connect May 2025
Reflection Period:
Nov 15, 2024 - May 4, 2025
Connects provide a regular touchpoint where you and your manager can come together with a growth mindset to reflect on impact and discuss areas for improvement and future development.
Fixed Mindset leads to a desire to look smart and therefore a tendency to avoid challenges, give up easily, see failures as fruitless or worse, ignore useful negative feedback and feel threatened by the success of others.
Growth Mindset leads to a desire to learn and therefore a tendency to embrace challenges, persist in the face of setback, see failures as essential to mastery, learn from criticism and find lessons and inspiration in the success of others.
Reflect on the past
At Microsoft, we have high performance expectations of everyone. We must strive to deliver on ambitious goals, accelerate our culture and act with speed and urgency. Capture what you’ve accomplished and learned since your last Connect.

------------------

## SDX

### Accessibility & Reliability Improvements:

- Collaborated with the **Fluent team** to resolve a **macOS-specific global styling issue** where the mouse pointer incorrectly displayed a hand cursor on button hover.
- Fixed **font height overlapping issues** by adjusting individual component settings by adding line height in every component. Meanwhile, we explored alternative approaches for a more reliable way to add **global styling solutions**: 
    - Explored global styling solutions with the Fluent team, but as pointed out, this is iPad specific only. 
    - Investigations suggest the root cause is likely related to **UIWebView** usage and migrating to **WKWebView** could solve this issue, as this behavior is seen elsewhere. Further investigations were needed to confirm this but as focus shifted to iOS, we shared findings with App Chat team.

- Investigated **1JS artifact consumption** in SDX to identify the source of **iPad ChatHistory scrolling issues**.
- Created a **patch on 1JS package** and coordinated **version bump in SDX** to revert a faulty PR.

- **Enabled Restshy for iPad**: Added dynamic expand/contract behavior via user interaction.  
    - **Regression**: Clicking on the chat expand Restshy component, and in expanded mode, suggestion pills required click twice due to component mutation happens before `onClick` event gets triggered.
    - **Actions taken to fix**:  
        - **Temp fix**: Force Restshy into permanent expanded state on iPad.  
        - **Collaborating with Fluent team**: Requested API enhancements for event timing and blur/click control.  

### 1JS to SDX Script:
* Facilitated **knowledge transfer** and helped resolve issues in the script used for **transferring lib folders from 1JS to SDX**.

### Enabling Copilot on GCC Accounts

1. **SDX Version Management & Collaboration:** 
    Continuous collaboration with the iPad SDX team in Redmond for following items:
    - Force update SDX Version to force update to latest SDX version on Mac.
    - Updating the Word and PPT to the GCC ring which needed enormous amounts of hit and trial as there was no documentation for testing which was a challenge.
    - Identified and documented environmental and infrastructure requirements for vendors to test for GCC ring which ranges from very small quirks eg: charger attached on force update, enabling flighting from Msft Ring, finding current SDX version on Prod by reading logs.

2. **Some other task related to it**
    - Conducted end-to-end validation of Copilot visibility and verified SDX configuration pointed to GCC servers.
    - Configuration of packet analyzer needed to inspect SDX traffic on Mac (Prod). Fiddler’s trial version worked briefly, but Charlie had issues decrypting HTTPS. Resolved it using iPhone setup docs to enable decryption for our case.
    - Coordinated with vendors and SDX team to ensure readiness for GCC testing.


## App Chat (OCM)
### Admin Controls for Multi-Account Copilot iOS (Word & PowerPoint)

**Key Contributions:**

- Implemented the **Admin Controls for Multi-Account Copilot** feature on the **OCM iOS platform** for both **Word and PowerPoint**.
- Disabled **nudge** display.
- Found a bug where on first time word install, app crashes on disabled copilot user due to null citation on prefetch, as well as a compliance issue happened due to **prefetch** enabled for disabled copilot enterprise user, both can be resolved by disabling prefetch for disabled users.
- **Compliance Fix – Prefetching Disablement:**
    - Moved `FCopilotDisabledByAdmin` from `PPTHvcChatPane` to `OCMAIChatClient`.
    - Explored two approaches:
        1. **Consume MSO API directly, instead of using actionCache:** 
            - As suggested by the Apex team to consume the **shared MSO API** directly.
            - Didn't go through this approach as UI thread was blocking when API is called, resulted in app crash. 
        2. **Use execution context to get `copilotInfoCache` (Chosen Approach):**
            - Introduced stability issues, such as **crashes due to missing execution context**.
            - Collaborated with the **Word and PowerPoint** team to integrate and consume the **MSO API**.
            - Updated `OCMAIChatClient` to now contain reference of `executionContext` on instantiation similar to Word implementation.
            - This ensured a reliable and reusable context reference, resolving the crash issues.

### Enable Safelink on App Chat iOS (PowerPoint & Word)
**Key Contributions:**
- **Enabled Safelink** for **iOS** platform, ensuring that all links are properly formatted and secure.
- Collaborated with **Biz Chat** team to raise issue for implementation in service instead of core for code restructuring.
- Notified other partner teams that they can enable Safelink in App Chat on their respective platforms.
- Fixed external citation issue where external citations were embedded as attribute in citation base url, avoiding redundant code.