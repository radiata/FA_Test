# FA_Test

Controls:
Movement - WASD
Jump - Space
Interact  - E
Toggle inventory menu - Escape
Zoom Item Inspector - Mouse Wheel
Rotate Item Inspector - Hold LMB and drag the Mesh
Items can be drag and dropped on other inventory slots and the item inspector slot in the bottom right
Dialogue is driven by mouse interaction only.

Testing notes:
In the editor preferences you will need to unbind Escape from "Play World" > "Stop"

Open the ThirdPersonMap

Play in the editor

Two collectable items are located in the level

One Interactable NPC is located in the level

Playing locally there have been no issues, but if for some reason there needs to be a recompilation and picking up items does not work, then you may need to change the Inventory Size back to 4 in the "PlayerInventory" Actor Component of "BP_ThirdPersonCharacter". Occasionally on recompile this setting has been going back to 0, since I set it up without a default value.


Design Choices:
I generally prefer using code over blueprints, because of the readability and ability to organize more easily, and the performance benefits for heavier tasks can be critical in some cases. But when creating a simple project or proof of concept I will generously supplement my code with blueprints for iteration speed. This is especially the case for anything related to UI and highly visual elements.

In this case I used C++ for data structures and reusable components, such as the Interactable Interface.


Interactables:
I created a simple interface to apply to all interactables, to reduce redundancy of code and allow for a relatively clean re-use of an interact prompt. The player has a debug interaction range left enabled, and the range and radius of the interacting are easily adjustable via the Third Person Blueprint. 
Collectable Item and Interactable NPC are simple blueprintable actors set up to handle implementation.


Inventory:
Item Data is a simple Data Class to be linked to a Collectable Item BP, that can be easily pointed to by the Inventory Data class. The Inventory Component can be assigned to any actor and linked to an Inventory Data to modify the underlying inventory. In this case an inventory is being initialized by the Inventory Component, but that initialization can be handled a number of ways with simple refactoring. Changing the initialization will allow dynamic linking and changing of different Inventory Data classes and Inventory Components. 

The Inventory UI is a simple set of Widget elements that are linked to inventory slots. I implemented a number of them as smaller reusable components, such as inventory slots, for easier modification and scalability.


Item Inspection:
For the 3D rendering of the inventory item, I haven't done a task like this in UE before, but the simplest reliable way to achieve it seemed to be a render texture. I would have liked to spend more time to figure out how to mask other objects from the render camera, but for a short term solution it is not too problematic to spawn the camera and mesh outside of the level bounds. There are some simple designer focused variables exposed to tweak behaviour, such as camera zoom clamping, rotation speed multipliers, and zoom speed multipliers. Further iteration could easily associate the settings with Item Data for zoom clamping to optimize the player viewing of an object.


Dialogue:
Like Items, Each Dialogue is linked to a Data Asset, which can be easily created and modified by designers in editor, or parsed from another source such as a database. There is simple information provided, and it currently flows linearly, but it could be expanded to have jumps to different dialogue "nodes" based on player choices (both past and current).


Character Controller:
I used the default Third Person controller as a base and made a C++ additions to include inputs for inventory and interaction. The Blueprint has the Inventory and Dialogue components added to it, and it contains logic for handling those as well as generating/managing our UI widgets.

