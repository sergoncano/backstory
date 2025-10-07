## How to write scripts for this program

- The script is written into the SCRIPT macro in the `include/script.h`
- The script needs to be within quotes
- End every line with "\n" if you want the newline to be displayed.
- Then add another "\" at the end if you're newlining it in your editor, otherwise the macro will crash. Such newline will not be taken into account by the renderer.

### Sections and jumps

- If you want to separate sections by prompting the user for a key press, add a "<BREAK_CHARACTER><BREAK_CHARACTER>". This and the following characters are defined in the `include/constants.h` file.
- You also _NEED_ to add those at the end of the script or the program will crash.
- In case you used separators, there is no need for a newline since the user itself will provide it.
- To jump from one line to another that isn't the next one, instead of adding two break characters at the end of it, add "<BREAK_CHARACTER>LABEL<BREAK_CHARACTER>". Then in the beginning of the line you want to jump to, add: "<JUMP_CHARACTER>LABEL<JUMP_CHARACTER>", this will not be rendered as part of the line, it will only be taken into account by the script to know where to jump to.
- To end the printing of the script prematurely, use "end" as the label, this can be configured by changing the END_KEYWORD constant.

### Interactive conditional jumps

- To create a choice, write the line of text that will be displayed presenting the choice then, at the end of it, start the label with a <CHOICE_CHARACTER>, then the rest of the label must be the number of options the choice will have, lets call it n.
- The next n lines must follow this pattern: The text will be what you want to be displayed as the option text. The label must be where you want to jump to if that option is taken.
- Do not write choices within choices, instead, have the option jump to a line that contains another choice.

### Customization and constants

- The amount of choices, lines of dialogue and other constants are defined in the `ìnclude/constants.h` file. Change them to suit your needs.
- The appearance of the choice prompt and the look of the options can be also configured through string constants for extra customization.

  I know this is not a clean or optimal implementation, and it would be much more convenient if the script was read from an outside file. However, for the use case I'm coding this for, I need the script built into the executable, so I won't be changing that. However, it is a very easy to implement feature, feel free to if you need it.
