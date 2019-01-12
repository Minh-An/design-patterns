#include <atomic>
using namespace std;
class Stack
{
  private:
    struct Node
    {
        Node *next_;
        int value_;
        Node(int value) : value_(value) {}
    };
    atomic<Node *> head_;

  public:
    ~Stack()
    {
        while (head_.load())
        {
            Node *next = head_.load()->next_;
            delete head_.load();
            head_ = next;
        }
    }

    void Push(int value)
    {
        Node *n = new Node(value);
        do
        {
            n->next_ = head_;
        } while (!head_.compare_exchange_strong(n->next_, n));
    }

    bool Pop(int &value)
    {
        Node *current_head = head_;
        while (current_head)
        {
            if (head_.compare_exchange_strong(current_head, current_head->next_))
            {
                value = current_head->value_;
                delete current_head;
                return true;
            }
        }
        return false;
    }
};