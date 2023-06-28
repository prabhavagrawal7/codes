# import re

# paragraph = "Insert images of famous artworks that have challenged traditional notions of beauty and aesthetics, such as Marcel Duchamp's Fountain or Kazimir Malevich's Black Square. Apply a Thanksgiving-themed template."

# # Regular expression pattern to match commands
# pattern = r"(?i)(?:insert|add|create|apply|change|format|include|use|showcase)\b.*?(?:template|slide|chart|transition|image|background\s*color|text\s*color|font|video|process\s*diagram|table|line\s*graph|timeline|quote|list|checklist|pie\s*chart|numbered\s*list)"

# matches = re.findall(pattern, paragraph)

# # Join the matched commands into a single string
# print(matches)
# matched_commands = ' '.join(matches)

# print(matched_commands)

import re

paragraph = "Hi prabhav, how are you? Create a slide about how your grandma died of tuberclosis. Insert images of famous artworks that have challenged traditional notions of beauty and aesthetics, such as Marcel Duchamp's Fountain or Kazimir Malevich's Black Square. Apply a Thanksgiving-themed template; Change the background color to red! Add a slide with a process diagram."

# Regular expression pattern to match commands
pattern = r"(?i)(?:insert|add|create|apply|change|format|include|use|showcase)\b.*?(?:template|slide|chart|transition|image|background\s*color|text\s*color|font|video|process\s*diagram|table|line\s*graph|timeline|quote|list|checklist|pie\s*chart|numbered\s*list)"

# Split the paragraph into separate commands
commands = re.split(r'\.|\!|;|\?', paragraph)

# Process each command
for command in commands:
    command = command.strip()
    
    if re.match(pattern, command):
        print(command)
