class Entity{
public:
    int x, y;

    Entity(int x, int y) {
        this -> x = x;
    }

    int GetX() const {
        const Entity* e = this;
        return e->x;
    }
};