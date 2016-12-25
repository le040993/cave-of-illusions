# *The Cave of Illusions*

*The Cave of Illusions* is a roguelike project set in the *Innocence Seekers* universe. While it is implemented in SDL, the first version is planned to be entirely text-based. Graphics (2D) is planned for later versions.

**Note:** This project is a work in progress. Many features are currently missing at the moment.

Planned features include:
- Character customisation — choose your character's stats, preferred weapons, and magical abilities.
- Multiple procedurally-generated dungeons; no two dungeons are the same.
- Tons of fearsome enemies. Each type of foe will be different, hence different strategies will be required.
- A hunger system linked to the character's mana. Your character's mana will slowly drain over time, even if she is not using magic. Replenish it (by eating, or by draining mana), or it will be her health which will drain instead.
- Hardcore mode. For players who want a challenge, hardcore mode means that if your character dies, that is it. Game over. You will need to start all over again.

## Building

- Windows: A Visual Studio solution is available.
- OS X: Support is planned.
- Linux: Support is planned.

## Notes on debugging

When debugging using Microsoft Visual Studio, make sure that the Working Directory setting in the Debugging section of the project properties is set to $(SolutionDir), not the default $(ProjectDir). This is because the program will look for fonts in "./font" (if it is not changed), and the program will abort if it cannot find the fonts. The relevant setting is not actually stored in the coi.vcproj file, but is considered a user-specific setting and as such is stored in coi.vcproj.user, which is excluded by the repository .gitignore file.
