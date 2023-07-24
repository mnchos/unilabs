#include <cstdlib>
#include <ctime>
#include <cmath>
#include <complex>
#include <GL/glut.h>
#define WIDTH 800
#define HEIGHT 640
#define RANGE 80
#define MAX 50
#define INDEX 0.01
#define RE_C 1.07
#define IM_C 0.0001

using namespace std;

//��������� ����� � ������������ (x, y) ������������ � ������� ������(RGB)
void draw_dot(int x, int y, GLubyte* clr) {
	glColor3ub(clr[0], clr[1], clr[2]); //���� ���������
	//�� ����� ������ �������, ��������� glVertex �������� �����
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

void draw_biomorph() {
	complex <double> z; //z ����� ����������� � ���
	//���������, �� ������ �������� ����� ����������� � z, ������������ � ���
	const complex <double> constant(RE_C, IM_C);
	double re_z, im_z; //������ �������������� � ������ ������ z �� ������� ��������
	//clr_black-���� ����, new_clr-���� ��������(RGB)
	GLubyte clr_black[] = { 0, 0, 0 }, new_clr[3];
	//������������� ������ ������������������, ������������ rand() ������� ��������  � ��������
	srand(time(0));
	//���������� z ��� ������ ����� ����
	for (int x = -WIDTH / 2; x < WIDTH / 2; x++) {
		for (int y = -HEIGHT / 2; y < HEIGHT / 2; y++) {
			//����������� ���������� ������� �����, re_z <= 4, im_z <= 3.2
			z.real(x * INDEX);
			z.imag(y * INDEX);
			//������ �������������� � ������ ������ z
			re_z = fabs(z.real());
			im_z = fabs(z.imag());
			//�������� z � ���, ���� ������ ��������������, ������ ����� ��� ������ ������ z
			//�� ���������� ������������� ����� �� ���������� ���������(RANGE)
			//MAX ������������ ����� �������� ��� ������,
			//���� z ������� ��� ������ ���������� � ���(�.�. ������� �� ��������� MAX)
			for (int i = 0; (re_z < RANGE || im_z < RANGE || abs(z) < RANGE) && i < MAX; i++) {
				//�������� ���������� �������� z � ��� �������� ���������
				z = pow(z, 3) + constant;
				re_z = fabs(z.real());
				im_z = fabs(z.imag());
			}
			//����������� z, �������� � �������, ���������� ���������� �����
			if (re_z < MAX || im_z < MAX * 50) {
				new_clr[0] = rand() % 255;
				new_clr[1] = rand() % 255;
				new_clr[2] = rand() % 255;
				draw_dot(x, y, new_clr);
			}
			else //�����, �� �������� � �������, ����������� ������ ����
				draw_dot(x, y, clr_black);
		}
	}
	glFlush(); //���������� ���� ����� �� �����
}

void init() {
	glClearColor(0.0, 0.0, 0.0, 0.0); //���� ����(RGBA, ������)
	glPointSize(4.0); //����� �������� 4x4 �������
	glMatrixMode(GL_PROJECTION); //������� ��������
	glLoadIdentity(); //������ ������� ������� �� ���������
	//��������� ������� ���������
	gluOrtho2D(-WIDTH / 2, WIDTH / 2, -HEIGHT / 2, HEIGHT / 2);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT); //������� �������� ������ �����
	glFlush();
	draw_biomorph(); //��������� ��������
}

int main(int argc, char** argv) {
	glutInit(&argc, argv); //������������� OpenGL Utility Toolkit
	//����� ����(��������� ����� � RGB-�������)
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	//��������� �������� ����(������ � ������ � ��������)
	glutInitWindowSize(WIDTH, HEIGHT);
	//��������� ���� ������������ ������ �������� ���� ������
	glutInitWindowPosition(50, 50);
	//�������� ���� c ���������� Biomorph
	glutCreateWindow("Biomorph");
	//������������� �������, ���������� �� ��������� � ����
	glutDisplayFunc(display);
	init(); // �������������� ���������
	glutMainLoop(); //���� � ������� ����
	return 0;
}