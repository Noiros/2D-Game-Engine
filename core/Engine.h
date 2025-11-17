class Engine {
public:
    void test();

    static void SetInstance(Engine* instance) { s_instance = instance; };
    static Engine& Get() { return *s_instance; };
    Engine(const Engine&) = delete;
    Engine& operator=(const Engine&) = delete;

private:
    static Engine* s_instance;
};

