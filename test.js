let paragraph = "Hi prabhav, how are you? Create a slide about how your grandma died of tuberclosis. Insert images of famous artworks that have challenged traditional notions of beauty and aesthetics, such as Marcel Duchamp's Fountain or Kazimir Malevich's Black Square. Apply a Thanksgiving-themed template; Change the background color to red! Add a slide with a process diagram.";

// Regular expression pattern to match commands
let pattern = /(?i)(?:insert|add|create|apply|change|format|include|use|showcase)\b.*?(?:template|slide|chart|transition|image|background\s*color|text\s*color|font|video|process\s*diagram|table|line\s*graph|timeline|quote|list|checklist|pie\s*chart|numbered\s*list)/;

// Split the paragraph into separate commands
let commands = paragraph.split(/[.!?;]/);

// Process each command
for (let command of commands) {
 command = command.trim();
 if (pattern.test(command)) {
 console.log(command);
 }
}
