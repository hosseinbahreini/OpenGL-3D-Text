#include <GL/glut.h>
#include <cstring>

float angle = 0.0f;

void render3DText(const char *text, float scale) {
    glPushMatrix();
    glScalef(scale, scale, scale);
    for (const char *c = text; *c != '\0'; c++) {
        glutStrokeCharacter(GLUT_STROKE_ROMAN, *c);
    }
    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(-3.0f, 0.0f, -20.0f);


    glRotatef(angle, 0.0f, 1.0f, 0.0f);

    glColor3f(0.8f, 0.5f, 0.1f);
    render3DText("HOSSEIN", 0.02f);

    glTranslatef(0.0f, -3.0f, 0.0f);
    render3DText("BAHREINI", 0.01f);

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (float)w / (float)h, 1.0f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
}

void timer(int value) {
    angle += 1.0f;
    if (angle > 360) {
        angle -= 360;
    }
    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("3D Text Example");

    glEnable(GL_DEPTH_TEST);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, timer, 0);

    glutMainLoop();
    return 0;
}

