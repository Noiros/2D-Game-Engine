#pragma once

class ClassDB
{
public:
    ClassDB();
    ~ClassDB();
    
    static void SetInstance(ClassDB* instance) { s_instance = instance; }
    static ClassDB& Get() { return *s_instance; }
    ClassDB(const ClassDB&) = delete;
    ClassDB& operator=(const ClassDB&) = delete;

private:
    static ClassDB* s_instance;
};
