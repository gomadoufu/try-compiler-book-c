// トークンの種類
typedef enum {
    TK_RESERVED,  // 記号
    TK_IDENT,     // 識別子
    TK_NUM,       // 整数トークン
    TK_EOF,       // 入力の終わりを表すトークン
} TokenKind;

typedef struct Token Token;

// トークン型
struct Token {
    TokenKind kind;  //トークンの型
    Token *next;     //次の入力トークン
    int val;         // kindがTK_NUMの場合、その数値
    char *str;       // トークン文字列
    int len;         //トークンの長さ
};

// 現在着目しているトークン
Token *token;

// 入力プログラム
char *user_input;

// 抽象構文木のノードの種類
typedef enum {
    ND_ADD,     // +
    ND_SUB,     // -
    ND_MUL,     // *
    ND_DIV,     // /
    ND_LT,      // <
    ND_LE,      // <=
    ND_EQ,      // ==
    ND_NE,      // !=
    ND_ASSIGN,  // =
    ND_LVAR,    // ローカル変数
    ND_NUM,     //整数
} NodeKind;

typedef struct Node Node;

// 抽象構文木のノードの型
struct Node {
    NodeKind kind;  // ノードの型
    Node *lhs;      // 左辺
    Node *rhs;      // 右辺
    int val;        // kindがND_NUMの場合のみ使う
    int offset;     // kindがND_LVARの場合のみ使う
};

Token *tokenize(char *p);

Node *code[100];
void program();

void gen(Node *node);

void error(char *fmt, ...);
void error_at(char *loc, char *fmt, ...);
