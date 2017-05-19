

class tokenizer {

public:
  tokenizer( std::string exp ) { expression = exp; }
  std::vector<Token *> &tokenize();
  
private:
  std::string expression;
  std::vector<Token *>  tokens;
  
}
