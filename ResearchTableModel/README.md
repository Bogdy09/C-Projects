This is a GUI application for managing researchers and their ideas, featuring role-specific functionalities and a table model for dynamic idea management. Key features include:

**Display and Sorting of Ideas**
-Ideas are displayed in a table with columns for title, description, status, creator, and duration.
-Ideas are automatically sorted by duration in ascending order for a clear and structured view.

**Role-Based Access**
**Senior Researchers:**
-Can accept proposed ideas, updating their status to "accepted."
**Other Researchers:**
-Can only view ideas; restricted from accepting proposals.

**Add New Ideas**
-Researchers can propose new ideas by providing:
A title.
A description.
A duration (1, 2, or 3).
-The application ensures valid input for durations and prevents empty titles.
-New ideas are added with the default "proposed" status and associated with the logged-in researcher.

**Dynamic Table Updates**
Utilizes a custom table_model to:
-Display sorted ideas.
-Dynamically add new ideas.
-Reflect status updates in real-time.

**Persistent Data**
Researchers and ideas are loaded from files (researchers.txt and ideas.txt).
Updates to ideas (e.g., adding or changing status) are maintained in memory.

This application provides an efficient and role-specific tool for researchers to collaborate, propose, and evaluate ideas interactively while ensuring clarity and validation.
