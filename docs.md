# How to write scripts for this program

- End every line with "\n" if you want the newline to be displayed.
- Then add another "\" at the end if you're newlining it in your editor, otherwise the macro will crash. Such newline will not be taken into account by the renderer.
- If you want to separate sections by prompting the user for a key press, add a "\b\b".
- You _NEED_ to add a "\b\b" at the end of the script or the program will crash.
