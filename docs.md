# How to write scripts for this program

- The script is written into the SCRIPT macro in the `include/script.h`
- The script needs to be within quotes
- End every line with "\n" if you want the newline to be displayed.
- Then add another "\" at the end if you're newlining it in your editor, otherwise the macro will crash. Such newline will not be taken into account by the renderer.
- If you want to separate sections by prompting the user for a key press, add a "\b\b".
- You _NEED_ to add a "\b\b" at the end of the script or the program will crash.
  I know this is not clean or optimal, and it would be much more convenient if the script was read from an outside file. However, for the use case I'm coding this for, I need the script built into the executable, so I won't be changing that. However, it is a very easy to implement feature, feel free to if you need it.
