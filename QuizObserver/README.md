This application uses the Observer Pattern to synchronize a Presenter GUI and multiple Participant GUIs for managing questions and participants.

**Key Features**

**Presenter GUI:**

Displays a sorted list of questions (ID---Text---Answer---Score).
Allows adding new questions with unique IDs and non-empty text.

**Participant GUI:**

Displays questions sorted by score in descending order.
Automatically updates when new questions are added.

**Observer Pattern**
The Repository acts as the subject, maintaining a list of observers (GUIs).
Changes to questions trigger a notify() method, updating all connected GUIs automatically.

**Persistence**
Questions and participants are loaded from files (questions.txt, participants.txt) and saved after updates.

This design ensures real-time synchronization and a dynamic, extensible system.






