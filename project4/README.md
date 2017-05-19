Program is running as intended.
argv[1] on the command lines accepts a cs315 formatted JSON file
argc is not used 

DirectoryEntry();
    
    int depth();//uses a helper function for eas of recursion
    std::string pwd();
    std::string cd();
    std::string cd(std::string path);//makes use of a queue to track directories 
    std::vector<std::string> ls();
    std::vector<std::string> ls(std::string path);
    DirectoryEntry *duplicate();
    DirectoryEntry *duplicate(std::string path);
    std::vector<std::string> find(std::string path);
    bool hasSubstructure(DirectoryEntry *dirEntry);
    bool areTheSame(DirectoryEntry *dirEntry);
    void move(std::string fromPath, std::string toPath);
