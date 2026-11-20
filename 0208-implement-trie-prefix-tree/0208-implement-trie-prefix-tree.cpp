
class Trie {
public:
    struct node
    {
        node* children[26] = {nullptr};
        bool isEnd = false;
    };

    node* root = new node();

    Trie() {}

    void insert(string word)
    {
        node* temp = root;

        for (char ch : word)
        {
            int i = ch - 'a';

            if (!temp->children[i])
                temp->children[i] = new node();

            temp = temp->children[i];
        }

        temp->isEnd = true;
    }

    node* walk(string s)
    {
        node* temp = root;

        for (char ch : s)
        {
            temp = temp->children[ch - 'a'];

            if (!temp)
                return nullptr;
        }

        return temp;
    }

    bool search(string word)
    {
        node* temp = walk(word);
        return temp && temp->isEnd;
    }

    bool startsWith(string prefix)
    {
        return walk(prefix) != nullptr;
    }
};
