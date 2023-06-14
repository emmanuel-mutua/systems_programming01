# systems_programming01

# File Record Management System

This program is a simple file record management system implemented in C. It allows the user to add records to a file, create an index for efficient record retrieval, and retrieve records based on a given key.

## Features

- Adding records: The program prompts the user to enter a data value and a key for each record to be added to the file. It checks if a record with the same key already exists and ensures that keys are unique. The records are stored in a file named "mfile".

- Index creation: The program creates an index that maps each key to the relative address of its corresponding record in the file. The index is stored in a separate file named "index_file".

- Record retrieval: The user can choose to retrieve records based on their keys. The program reads the index from "index_file" and retrieves the corresponding record from "mfile" based on the provided key. The data value of the retrieved record is displayed.


