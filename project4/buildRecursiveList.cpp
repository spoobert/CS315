#include "ListNode.hpp"
#include "Lex.hpp"

ListNode *buildList(Lex *lex)
{
    Token token = lex->getToken();
    ListNode* list = new ListNode();

    if( token.isEndOfText() )
      return list;

    if( ! token.isLeftParen() )
      return nullptr;

    token = lex->getToken();

    while( token.isName() ){
      ListNode* atom = new ListNode( token.getName() );
      list->addChildNode( atom );
      token = lex->getToken();
    }

    if( token.isRightParen() )
      return list;

    lex->ungetToken();
    ListNode* tmp;
    while( (tmp = buildList( lex ) ) ){
      list->addChildNode(tmp);
      token = lex->getToken();

      while( token.isName() ){
        ListNode* atom = new ListNode( token.getName() );
        list->addChildNode( atom );
        token = lex->getToken();
      }

      if( token.isRightParen() )
        return list;

      lex->ungetToken();
    }
    if( token.isRightParen() )
      return list;

    return nullptr;

    // build the internal representation of a recursive list and return a pointer to it.
}

// void printList(ListNode *list, int level)
// {   // Recursively, print the nodes of "list", starting at indentation level, "level".
//     // The children of "list" get printed at "level + 1", their children at "level +2", etc.
// }

void printList(ListNode *list)
{
    if( list == nullptr )
        return;  // an empty list doesn't have any representation.
    else if( list->isAtom() ) {
        std::cout << " " << list->getAtom() << " ";
    } else {
        std::cout << "(";
        std::vector<ListNode *> children = list->getChildren();
        for( auto child = children.begin(); child != children.end(); ++child )
            printList(*child);
        std::cout << ")";
    }
}

const int spacesPerTab = 4;  // 4 spaces for each level of indentation

void printList(ListNode *list, int level)
{
    if( list == nullptr )
      return;
    else if( list->isAtom() ){
      for(int i = 0; i < level*spacesPerTab; i++ )
        std::cout << " ";
      std::cout << list->getAtom();
      std::cout << std::endl;
    } else {
      for(int i = 0; i < level*spacesPerTab; i++ )
      std::cout << " ";
      std::cout << "(" << std::endl;
      std::vector<ListNode*> children = list->getChildren();
      for( auto child = children.begin(); child != children.end(); ++child )
        printList(*child, level + 1);
        for(int i = 0; i < level*spacesPerTab; i++ )
        std::cout << " ";
        std::cout << ")" << std::endl;

    }
    // print a list at an indentation specificed by "level".
    // Note that std::cout << string( level * spacesPerTab, ' ' ); prints
    // "level * spacesPerTab" spaces. You can use this construct to
    // print the right number of spaces for different values of "level".
}
/*
void destroy(ListNode* list)
{
    // findMin
   list = list->getChildren();
    // delete the nodes of the list that "list" points to, recursively.
}
*/
int main()
{
    std::string input = "(a b (  ( (f g) e (((f) g) h) (h (i)))) )";
    Lex *lex = new Lex(input);

    // The list is included in parentheses. That is. ( ( () () ) () ) is
    // acceptable but ( () ) () is not.

    ListNode *list = buildList(lex);
    printList(list,0);
    std::cout << std::endl;

  //  destroy(list);
    return 0;
}
