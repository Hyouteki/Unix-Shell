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
- **Options**
    - **ls**
    *-a: for listing all the files along with the hidden files*<br>
    *-m: for listing the files seperated by commas*<br>
3) cat {
    -E: for printing the content with highlighting the line endings
    -n: for printing the content with line numbers }
4) date {}
5) mkdir {
    -m: for creating a directory with specific permissions
    -v: for verbose(ly) making the directory }
6) rm {
    -i: for asking confirmation before removing the file
    -v: for verbose(ly) removing the file }

== Error handled ==
1) Multiple &t error
2) Wrong command error
