#include<GL/freeglut.h>
#include<iostream>

GLfloat escala = 1, deslocax = 0, deslocay = 0;

void inicializacao(void);

void listeningkey(unsigned char tecla, GLint x, GLint y){

    switch(tecla){
        case '+': escala = escala + 0.1f;
                break;
        case '-': escala = escala - 0.1f;
                break;
        case '1': if (deslocax < 2)
                deslocax = deslocax - 0.2f;
                break;
        case '2': deslocax = deslocax + 0.2f;
                break;
        case '3': deslocay = deslocay - 0.2f;
                break;
        case '4': deslocay = deslocay + 0.2f;
                break;
    }
    inicializacao();
}


void desenhaLinha(void){

    glLineWidth(8);
    glBegin (GL_LINES);

        glVertex2f(0,2);
        glVertex2f(0,-2);

        glVertex2f(0,2);
        glVertex2f(1,-2);

        glVertex2f(1,-2);
        glVertex2f(1,2);

        glEnd();
}
void desenhaTriangulo(void){

        glBegin(GL_TRIANGLES);
        glColor3f(0,1,0);
        glVertex2f(-2.5f, -2.5f);
        glVertex2f(2.5f, -2.5f);
        glColor3f(1,0,0);
        glVertex2f(0.0f, 2.5f);
        glEnd();


    glFlush();
}
void inicializacao(void){

    glClear( GL_COLOR_BUFFER_BIT );

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-3, 3,-3, 3);

    glScalef(1, escala, 0); // quando não for utilizar a escala, utilizar 1 (1, escala, 1): a escala é atribuída apenas para o Y.
    glTranslatef(deslocax, 0, 0);
    glTranslatef(0, deslocay, 0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    desenhaLinha();
    //desenhaTriangulo();

    glFlush();
}

int main(int argc, char* argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB );
    glutInitWindowSize(800,600);
    glutCreateWindow("Ola Glut");
    glutDisplayFunc(inicializacao);
    glutKeyboardFunc(listeningkey);
    glClearColor( 1, 0, 1, 0);
    glutMainLoop();

    return 0;
}
