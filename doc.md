# Assumptions
- **Taking max characters in a command to be 100**<br>
- **Taking max words in a command to be 10**<br>

# Information
- **CUSTOM SHELL can perform 11 total commands** 
    ```
    cd
    pwd
    exit
    ls
    cat
    date
    rm
    mkdir
    help
    echo
    clear
    ```
- **Command options**
    - **ls**<br>
    *-a: for listing all the files along with the hidden files*<br>
    *-m: for listing the files seperated by commas*<br>
    - **cat**<br>
    *-E: for printing the content with highlighting the line endings*
    *-n: for printing the content with line numbers*<br>
    <!-- <br> -->
    - **mkdir**<br>
    *-m: for creating a directory with specific permissions*<br>
    *-v: for verbose(ly) making the directory*<br>
    <!-- <br> -->
    - **rm**<br>
    *-i: for asking confirmation before removing the file*<br>
    *-v: for verbose(ly) removing the file*<br>
    - **else**<br>
    *&t: for executing command using threads*<br>

# Error handled
- **Multiple &t error**
- **Wrong command error**