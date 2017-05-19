#include "reclists.hpp"
#include "solutions.hpp"

// As you implement functions in this file, you should add the
// function-prototype to the solutions.hpp. The function-prototypes
// for append and reverse are already in solutions.hpp.

//((d))

list flat( list p ){
  if( is_null(cdr(p)))
    return p;

  if( is_atom(car(p)))
    cons( car(p), flat(cdr(p)));
  return append( flat( car(p) ), flat( cdr(p) ) );
}

//( a b c ) -> ( (a) (b) (C) )
//TODO study when should return p or null as base case
/*
list unFlat( list p ){
  if( is_null( cdr(p) ) )
    return cons( p, null());
  return cons( cons( car(p), null() ), unFlat( cdr(p) ) );
}
*/





/*
list flat( list p ){
  if( is_null( p ) )
    return p;
  if( is_atom( car( p ) ) )
    return cons( car( p ) , flat( cdr( p ) ) );
  return append( flat( car( p ) ) , flat( cdr( p ) ) );
}
*/

list unFlat( list p ){
  if( is_null( p ) )
    return null();
  return cons( car( p ) , cons( unFlat( cdr( p ) ) , null() ) );
}

list append( list p, list q )
{
     if( is_null( p ) ) return q;
     return cons( car(p), append( cdr(p), q ));
}

list reverse( list p )
{
     if( is_null(p) || is_atom(p) ) return p;
     return append( reverse( cdr(p) ), cons(car(p), null() )) ;
}

bool is_lat( list p )
{
  if( is_atom( car( p ) ) && is_null( cdr( p ) ) )
    return true;
  if( is_atom( car( p ) ) )
    is_lat( cdr( p ) );
  return false;

}
// (a b c)
bool member( list p, list q )
{
  if( is_null( q ) )
    return false;
  if( eq( p, car( q ) ) )
    return true;
  member( p, cdr( q ) );
  return false;
}
