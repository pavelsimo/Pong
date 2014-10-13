
#include "Drawing.h"

namespace draw
{
    void DrawLine( const math::Vector2 origin, const math::Vector2 end, 
        LINE_TYPE type, float width )
    {
        glPushMatrix();

        // LINES
        glLineWidth( width );

        if( type != SOLID )
        {
            glEnable ( GL_LINE_STIPPLE );

            if( type == DASHED )
                glLineStipple (1, 0x00FF);   /*  dashed   */
            else
                glLineStipple (1, 0x0101); /* dotted */
        }

        glBegin( GL_LINES );
            glVertex2f( origin.x, origin.y );
            glVertex2f( end.x, end.y );
        glEnd();

        if( type != SOLID )
        {
            glDisable( GL_LINE_STIPPLE );
        }

        glPopMatrix();  
    }
}
