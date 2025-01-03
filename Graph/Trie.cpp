class trie{
public:
struct node{
    map<char, node*> children;
    int prefix;
    vector<string> wend;
    node(){
        prefix=0;
    }
};
node *root;
trie(){
    root = new node();
}
void insert(string s){
    node* nd = root;
    int i=0;
    while(i<s.length()){
        if(nd->children[s[i]]!=NULL){
            nd = nd->children[s[i]];
            nd->prefix++;
            i++;
            continue;
        }
        nd->children[s[i]] = new node();
        nd = nd->children[s[i]];
        nd->prefix++;
        i++;
    }
    nd->wend.push_back(s);
}


int search_word(string s){
    node *nd = root;
    int i=0;
    while(i<s.length()){
        if(nd->children[s[i]]!=NULL){
            nd = nd->children[s[i]];
            if(nd->prefix==1)return i;
            i++;
        }
    }
    return i;
}
};
 