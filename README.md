# systems_programming01

# File Record Management System

This program is a simple file record management system implemented in C. It allows the user to add records to a file, create an index for efficient record retrieval, and retrieve records based on a given key.

## Features

- Adding records: The program prompts the user to enter a data value and a key for each record to be added to the file. It checks if a record with the same key already exists and ensures that keys are unique. The records are stored in a file named "mfile".

- Index creation: The program creates an index that maps each key to the relative address of its corresponding record in the file. The index is stored in a separate file named "index_file".

- Record retrieval: The user can choose to retrieve records based on their keys. The program reads the index from "index_file" and retrieves the corresponding record from "mfile" based on the provided key. The data value of the retrieved record is displayed.

## Usage

1. Compile the code using a C compiler.
2. Run the executable file.
3. Follow the prompts to add records to the file.
4. To retrieve a record, enter '1' when prompted. Provide the key of the record you want to retrieve.

## Dependencies

The code uses the standard C libraries: `stdio.h`, `string.h`, and `stdlib.h`.

## Limitations

- The program supports a maximum of 50 records.
- The keys are integers, limited to the range of `int` type.
- The program assumes that the data values entered by the user do not exceed 10 characters in length.

## Contributing

Contributions to the project are welcome. If you find any issues or have suggestions for improvements, please feel free to open an issue or submit a pull request.

## License

This program is released under the [MIT License](LICENSE).

## Acknowledgments

This program was developed as a learning exercise and is based on a basic file record management concept.

