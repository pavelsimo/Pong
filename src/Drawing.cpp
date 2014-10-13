
#include "Drawing.h"

namespace draw
{
    void DrawLine( const math::Vector2 origin, const math::Vector2 end, 
        LINE_TYPE type, float width )
    {
        glPushMatrix();
        glLineWidth( width );

        if( type != SOLID )
        {
            glEnable ( GL_LINE_STIPPLE );

            if( type == DASHED )
            {
                // dashed
                glLineStipple (1, 0x00FF);
            }
            else
            {
                // dotted
                glLineStipple (1, 0x0101);
            }
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

    void DrawQuad(float minX, float minY, float maxX, float maxY)
    {
        glPushMatrix();
        glBegin( GL_QUADS );
            glColor3f(1.f, 1.f, 1.f); 
            glVertex2f(minX, minY);
            glVertex2f(maxX, minY);
            glVertex2f(maxX, maxY);
            glVertex2f(minX, maxY);
        glEnd();
        glPopMatrix();
    }
}

