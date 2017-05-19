
bool isList(Lex *lex) 
{
     /*                                                                                                                          
                                                                                                                                  
     (((()) ()) ((()) () () () (())))                                                                                         
                                                                                                                                  
   */


    Token token = lex->getToken();
    if( token.isEndOfText() )
        return true;
    
    if( ! token.isLeftParen() )
        return false;

    token = lex->getToken();     
    if( token.isRightParen() )   
        return true;
    lex->ungetToken();           
    if( isList(lex) ) {
 
        token = lex->getToken();  
        return token.isRightParen();
    }

    return false;
}




bool isList(Lex *lex) 
{

   /*                                                                                                                              
     (((()) ()) ((()) () () () (())))                                                                                             
   */


    Token token = lex->getToken();
    if( token.isEndOfText() )
        return true;
    
    if( ! token.isLeftParen() )  // a linearly nested list starts with an open parenthesis.
        return false;

    token = lex->getToken();     

    // Are we at the base case? That is, did we just get a right parenthesis 
    // that matches the left parenthesis that we saw above? 

    if( token.isRightParen() )   // If so, return
        return true;

    // No, we didn't see a right parenthesis. We either have a bad token or we have
    // a linearly nested list to parse. Put the token back and parse such list by
    // calling this function recursively. 

    lex->ungetToken();           
    if( isList(lex) ) {
        // So, at the top of this function, we saw a left parenthesis.
        // In between, we parsed a linearly nested list. Now, we should
        // see the right parenthesis that matches the left one.

        token = lex->getToken();  
        return token.isRightParen();
    }

    return false;
}


bool isList( Lex * lex)
{

  /*
     (((()) ()) ((()) () () () (())))
   */
	Token token = lex -> getToken();

	if( token.isEndText() )
	    return " shits empty yo";

	
	if( ! token.LeftParnth() )
	    return false;


	token = lex -> getToken();


	if( token.isRightParn() )
	    return true;

	lex -> ungetToken();

	if( ! isList( lex ) )
	    return false;
	if( ! isList( lex ) )
	    return false;
	if( ! isList( lex ) )
	    return false;
	token -> getToken();
	if( token.isRightParn() )
	    return true;
	return false;
}
