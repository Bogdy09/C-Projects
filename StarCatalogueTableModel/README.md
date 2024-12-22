This is a GUI application for managing astronomers and stars, utilizing a table model to display, filter, and update star data interactively. Key features include:

**Display Stars in a Table:** Stars are presented in a structured table with columns for name, constellation, right ascension (RA), declination (DEC), and diameter, making data easy to view and understand.

**Filter Stars by Constellation:** Users can filter the stars based on the constellation of the logged-in astronomer. The table updates dynamically to show only the relevant stars when the filter is applied.

**Add New Stars:** Users can add stars by providing details such as name, coordinates (RA and DEC), diameter, and constellation. Validation ensures:

**Dynamic Table Updates:** The application leverages a custom table model (stars_table_model) to:

-Display filtered stars.
-Reset the view to show all stars.
-Dynamically add new stars to the table.

This application combines table-based data visualization with interactive filtering and real-time updates, offering a robust tool for astronomers to manage and analyze star data efficiently.
