
#include "Drawing.h"
#include <iostream>

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

    void DrawTexture(
        GLfloat x, GLfloat y, 
        GLuint texId,
        GLuint imgWidth, GLuint imgHeight, 
        GLuint texWidth, GLuint texHeight,
        Rect* clip
    ) 
    {
        if(texId != 0)
        {
            glPushMatrix();


            GLfloat texTop = 0.f;
            GLfloat texBottom = (GLfloat)imgHeight / (GLfloat)texHeight;
            GLfloat texLeft = 0.f;
            GLfloat texRight = (GLfloat)imgWidth / (GLfloat)texWidth;

            GLfloat quadWidth = imgWidth;
            GLfloat quadHeight = imgHeight;

            if(clip != NULL) 
            {
                texLeft = clip->x / texWidth;
                texRight = (clip->x + clip->w) / texWidth;
                texTop = clip->y / texHeight;
                texBottom = (clip->y + clip->h) / texHeight;
                
                // vertex coordinates
                quadWidth = clip->w;
                quadHeight = clip->h;
            }

            // move to rendering point
            glTranslatef(x, y, 0.f);

            // set texture id
            glBindTexture(GL_TEXTURE_2D, texId);

            // render texture quad
            glBegin(GL_QUADS);
                glTexCoord2f(texLeft,  texTop);    glVertex2f(0.f,       0.f);
                glTexCoord2f(texRight, texTop);    glVertex2f(quadWidth, 0.f);
                glTexCoord2f(texRight, texBottom); glVertex2f(quadWidth, quadHeight);
                glTexCoord2f(texLeft,  texBottom); glVertex2f(0.f,       quadHeight);
            glEnd();

            // unbind the texture
            glBindTexture(GL_TEXTURE_2D, 0);

            glPopMatrix();
        }
    }

}

