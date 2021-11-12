#include <cstring>

class N {
    public:
        N(int value) { this->value = value; }
        N operator+(N &arg) { return N(arg.value + this->value); }
        N operator-(N &arg) { return N(this->value - arg.value); }

        void setAnnotation(char *argument)
        {
            size_t n;

            n = strlen(argument);
            memcpy(this->buffer, argument, n);
            return;
        }

    private:
        char *buffer;
        int   value;
};

int main(int argc, char **argv)
{
    N  *first;
    N  *second;

    if (argc < 2)
    {
        _exit(1);
    }

    first = new N(5);
    second = new N(6);

    first->setAnnotation(argv[1]);

    (***second)(second, first);
    return (0);
}
