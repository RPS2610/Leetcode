class BrowserHistory {
    
    struct Node {
        string url;
        Node* prev;
        Node* next;

        Node(string u) {
            url = u;
            prev = nullptr;
            next = nullptr;
        }
    };

    Node* current;

public:
    BrowserHistory(string homepage) {
        current = new Node(homepage);
    }
    
    void visit(string url) {
        Node* newPage = new Node(url);

        current->next = nullptr;

        newPage->prev = current;
        current->next = newPage;

        current = newPage;
    }
    
    string back(int steps) {
        while (steps > 0 && current->prev != nullptr) {
            current = current->prev;
            steps--;
        }

        return current->url;
    }
    
    string forward(int steps) {
        while (steps > 0 && current->next != nullptr) {
            current = current->next;
            steps--;
        }

        return current->url;
    }
};