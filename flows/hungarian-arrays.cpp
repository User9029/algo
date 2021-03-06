t e m p l a t e < t y p e n a m e   T >  
 c l a s s   h u n g a r i a n   {  
     p u b l i c :  
     s t a t i c   c o n s t   i n t   M A X _ N   =   . . .   +   1 ;  
  
     i n t   n ;  
     i n t   m ;  
     T   a [ M A X _ N ] [ M A X _ N ] ;  
     T   u [ M A X _ N ] ;  
     T   v [ M A X _ N ] ;  
     i n t   p a [ M A X _ N ] ;  
     i n t   p b [ M A X _ N ] ;  
     i n t   w a y [ M A X _ N ] ;  
     T   m i n v [ M A X _ N ] ;  
     b o o l   u s e d [ M A X _ N ] ;  
     T   i n f ;  
  
     h u n g a r i a n ( i n t   _ n ,   i n t   _ m )   :   n ( _ n ) ,   m ( _ m )   {  
         a s s e r t ( n   < =   m ) ;  
         T   z e r o   =   T { } ;  
         f i l l ( u ,   u   +   n   +   1 ,   z e r o ) ;  
         f i l l ( v ,   v   +   m   +   1 ,   z e r o ) ;  
         f i l l ( p a ,   p a   +   n   +   1 ,   - 1 ) ;  
         f i l l ( p b ,   p b   +   m   +   1 ,   - 1 ) ;  
         i n f   =   n u m e r i c _ l i m i t s < T > : : m a x ( ) ;  
     }  
  
     i n l i n e   v o i d   a d d _ r o w ( i n t   i )   {  
         f i l l ( m i n v ,   m i n v   +   m   +   1 ,   i n f ) ;  
         f i l l ( u s e d ,   u s e d   +   m   +   1 ,   f a l s e ) ;  
         p b [ m ]   =   i ;  
         p a [ i ]   =   m ;  
         i n t   j 0   =   m ;  
         d o   {  
             u s e d [ j 0 ]   =   t r u e ;  
             i n t   i 0   =   p b [ j 0 ] ;  
             T   d e l t a   =   i n f ;  
             i n t   j 1   =   - 1 ;  
             f o r   ( i n t   j   =   0 ;   j   <   m ;   j + + )   {  
                 i f   ( ! u s e d [ j ] )   {  
                     T   c u r   =   a [ i 0 ] [ j ]   -   u [ i 0 ]   -   v [ j ] ;  
                     i f   ( c u r   <   m i n v [ j ] )   {  
                         m i n v [ j ]   =   c u r ;  
                         w a y [ j ]   =   j 0 ;  
                     }  
                     i f   ( m i n v [ j ]   <   d e l t a )   {  
                         d e l t a   =   m i n v [ j ] ;  
                         j 1   =   j ;  
                     }  
                 }  
             }  
             f o r   ( i n t   j   =   0 ;   j   < =   m ;   j + + )   {  
                 i f   ( u s e d [ j ] )   {  
                     u [ p b [ j ] ]   + =   d e l t a ;  
                     v [ j ]   - =   d e l t a ;  
                 }   e l s e   {  
                     m i n v [ j ]   - =   d e l t a ;  
                 }  
             }  
             j 0   =   j 1 ;  
         }   w h i l e   ( p b [ j 0 ]   ! =   - 1 ) ;  
         d o   {  
             i n t   j 1   =   w a y [ j 0 ] ;  
             p b [ j 0 ]   =   p b [ j 1 ] ;  
             p a [ p b [ j 0 ] ]   =   j 0 ;  
             j 0   =   j 1 ;  
         }   w h i l e   ( j 0   ! =   m ) ;  
     }  
  
     i n l i n e   T   c u r r e n t _ s c o r e ( )   {  
         r e t u r n   - v [ m ] ;  
     }  
  
     i n l i n e   T   s o l v e ( )   {  
         f o r   ( i n t   i   =   0 ;   i   <   n ;   i + + )   {  
             a d d _ r o w ( i ) ;  
         }  
         r e t u r n   c u r r e n t _ s c o r e ( ) ;  
     }  
 } ; 