#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

struct sample_data
{
    int     num;
    string  str;
};

// Creates file if doesn't exist yet
void create_file( const char* filename )
{
    // If file doesn't exist ofstream will create while trying to open non-existing file
    ofstream file(filename);
    file.close();
}

void write_to_file(const char* filename, const vector<sample_data>& data)
{
    // ofstream is for output, meaning it contains the output of our program, i.e. data we need to write
    // ofstream == write to file
    ofstream file( filename );

    // No need to check for `is_open`, if file doesn't exist it will be created
    for ( size_t i = 0; i < data.size(); ++i)
    {
        const sample_data& record = data[i];
        file << "  Record " << i << ": " << record.num << ", " << record.str << '|';

        if ( file.bad() )
        {
            cout << "Error writing record [" << i << "]" << endl;
            break;
        }
    }

    file.close();
}

vector<string> read_lines( const char* filename )
{
    // ifstream is for input, meaning file contains input data for our program that we need to read
    // ifstream == read from file
    ifstream file( filename );

    // If file doesn't exist we cannot open it for read as there is nothing to read from
    // in such case we throw an exception
    if ( !file.is_open() ) {
        throw std::runtime_error( "File doesn't exist." );
    }

    vector<string> file_data;

    while ( !file.eof() )
    {
        string line_from_file;
        getline( file, line_from_file, '|' );

        if ( !line_from_file.empty() )
            file_data.push_back( line_from_file );
    }

    file.close();

    return file_data;
}

void print_file_content( const char* filename )
{
    try
    {
        vector<string> lines_from_file = read_lines( filename );

        cout << "Lines from file:\n";
        for (string& s : lines_from_file)
            cout << s << endl;
    }
    catch (std::exception& error)
    {
        std::cout << "Caught an exception: " << error.what() << endl;
    }
}

int main(int argc, const char * argv[])
{
    cout << "Case 1: try to write to non-existing file and read from it\n";
    const char* file_name = "in_out_test.txt";
    const vector<sample_data> data = { { 101, "One-O-One" }, {42, "Forty Two" } };
    write_to_file( file_name, data );
    print_file_content( file_name );

    cout << "\n----------------------------------------------------------------------\n";
    cout << "Case 2: try to read from non-existing file, we should get an exception\n";
    const char* invalid_file_name = "failed_test.txt";
    print_file_content( invalid_file_name );

    cout << "\n----------------------------------------------------------------------\n";
    cout << "Case 3: create empty file and try again, should be no exception\n";
    create_file( invalid_file_name );
    print_file_content( invalid_file_name );
}
