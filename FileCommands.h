//
// Created by Dimitar on 2.5.2017 г..
//

#ifndef SVG_FILECOMMANDS_H
#define SVG_FILECOMMANDS_H


class FileCommand{

public:

    const char* getName() const;
    const char* getPath() const;

    FileCommand(const char* n = "Undefined", const char* p = "Undefined");
    FileCommand(const FileCommand&);
    FileCommand& operator= (const FileCommand&);
    ~FileCommand();

    bool operator==(const FileCommand&);
    friend std::istream& operator>>(std::istream& in, FileCommand&);
    friend std::ostream& operator<<(std::ostream& out, const FileCommand&);

private:
    char* name;
    char* path;

    void Copy(const FileCommand&);
};


#endif //SVG_FILECOMMANDS_H
