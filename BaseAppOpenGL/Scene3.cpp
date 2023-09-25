#include "Scene3.h"
#include <vector>
#include <ctime>

CScene3::CScene3()
{
	pCamera = NULL;
	pTexto = NULL;
	pTextures = NULL;

	bIsWireframe = false;
	bIsCameraFPS = true;

	iFPS = 0;
	iFrames = 0;
	ulLastFPS = 0;
	szTitle[256] = 0;

	// Cria gerenciador de impressão de texto na tela
	pTexto = new CTexto();

	// Cria camera
	pCamera = new CCamera(0.0f, 1.0f, 20.0f, 0.1f);

	// Cria o Timer
	pTimer = new CTimer();
	pTimer->Init();

	fTimerPosY = 0.0f;
	fRenderPosY = 0.0f;

	// Carrega todas as texturas
	pTextures = new CTexture();

	pTextures->CreateTextureMipMap(0, "../Scene1/CRATE.BMP");
	pTextures->CreateTextureMipMap(1, "../Scene1/TriangleFaces.bmp");
	pTextures->CreateTextureMipMap(2, "../Scene1/grama.bmp");
	pTextures->CreateTextureMipMap(3, "../Scene1/parede.bmp");
	pTextures->CreateTextureMipMap(4, "../Scene1/paredejanela.bmp");
	pTextures->CreateTextureMipMap(5, "../Scene1/paredeporta.bmp");
	pTextures->CreateTextureMipMap(6, "../Scene1/R1.jpg");
	pTextures->CreateTextureMipMap(7, "../Scene1/CasaTex.jpg");
	pTextures->CreateTextureMipMap(8, "../Scene1/snow_1.bmp");

	fRotY = 0.0f;

	iAngle = -45;

	bState = false;

	fPosX = 0.0f;
	fPosY = 0.0f;
	fPosZ = 0.0f;

	randomCube = 0;

	vector1 = 0;
	vector2 = 0;
	vector3 = 0;
	vector4 = 0;
	vector5 = 0;

	R = 0;
	G = 0;
	B = 0;

	for (int i = 0; i < 38; i++)
		faceColor[i] = { (rand() % 255), (rand() % 255), (rand() % 255) };

}


CScene3::~CScene3(void)
{
	if (pTexto)
	{
		delete pTexto;
		pTexto = NULL;
	}

	if (pTextures)
	{
		delete pTextures;
		pTextures = NULL;
	}

	if (pCamera)
	{
		delete pCamera;
		pCamera = NULL;
	}

	if (pTimer)
	{
		delete pTimer;
		pTimer = NULL;
	}
}




int CScene3::DrawGLScene(void)	// Função que desenha a cena
{
	// Get FPS
	if (GetTickCount() - ulLastFPS >= 1000)	// When A Second Has Passed...
	{
		ulLastFPS = GetTickCount();				// Update Our Time Variable
		iFPS = iFrames;							// Save The FPS
		iFrames = 0;							// Reset The FPS Counter
	}
	iFrames++;									// FPS counter

	pTimer->Update();							// Atualiza o timer

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limpa a tela e o Depth Buffer
	glLoadIdentity();									// Inicializa a Modelview Matrix Atual


	// Seta as posições da câmera
	pCamera->setView();

	// Desenha grid 
	Draw3DSGrid(20.0f, 20.0f);

	// Desenha os eixos do sistema cartesiano
	DrawAxis();

	// Modo FILL ou WIREFRAME (pressione barra de espaço)	
	if (bIsWireframe)
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	else
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//                               DESENHA OS OBJETOS DA CENA (INÍCIO)
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	glColor4ub(255, 255, 255, 255);



	//// Modificar o código da função e do render para que desenhe os cubos com a
	//// seguinte definição de CORES:
	//// Cubos com coordenadas X positivas e Y menor que zero => AZUL
	//// Cubos com coordenadas X negativas e Y maior que zero => VERDE
	//// Cubos com coordenadas X e Y iguais => VERMELHO
	//for (int i = -10; i <= 10; i += 2)
	//{
	//	for (int j = -10; j <= 10; j += 2)
	//	{
	//		glPushMatrix();
	//		glTranslatef(i, j, 0.0f);
	//		glRotatef(fRotY, 0.0f, 1.0f, 0.0f);

	//		// Mudar a cor segundo a lógica
	//		if ((i > 0) && (j < 0))
	//			glColor3f(0.0f, 0.0f, 1.0f);
	//		else if ((i < 0) && (j > 0))
	//			glColor3f(0.0f, 1.0f, 0.0f);
	//		else if (i == j)
	//			glColor3f(1.0f, 0.0f, 0.0f);
	//		else
	//			glColor3f(1.0f, 1.0f, 1.0f);
	//		
	//		DrawCube();
	//		glPopMatrix();
	//	}
	//}

	//if (fRotY == 360) {
	//	fRotY = 0;
	//}
	//else {
	//	fRotY++;
	//}

	
	//glPushMatrix();
	//glTranslatef(fPosX, fPosY, fPosZ);
	//DrawPyramid();
	//glPopMatrix();



	/*
	for (int i = -500; i <= 500; i += 50)
	{
		for (int j = -500; j <= 500; j += 50)
		{
			// Casa
			glPushMatrix();
			glTranslatef(i, 0.0f, j);
			glBegin(GL_TRIANGLES);
			for (int i = 0; i < 68; i++)
			{
				int p1 = vCasaIndexes[i].p1;
				int p2 = vCasaIndexes[i].p2;
				int p3 = vCasaIndexes[i].p3;

				glColor3ub(((-6.12f + vCasaVertices[p3].z) + 200.0f), ((-6.12f + vCasaVertices[p3].z) + 200.0f), ((-6.12f + vCasaVertices[p3].z) + 200.0f));

				/*if (vCasaVertices[p3].z > 5.0f)
					glColor3ub(255, 255, 255);
				if ((vCasaVertices[p3].z <= 4.0f) && (vCasaVertices[p3].z >= -4.0f))
					glColor3ub(128, 128, 128);
				if (vCasaVertices[p3].z < -5.0f)
					glColor3ub(50, 50, 50);


				glVertex3f(vCasaVertices[p1].x, vCasaVertices[p1].y, vCasaVertices[p1].z);
				glVertex3f(vCasaVertices[p2].x, vCasaVertices[p2].y, vCasaVertices[p2].z);
				glVertex3f(vCasaVertices[p3].x, vCasaVertices[p3].y, vCasaVertices[p3].z);

			}
			glEnd();
			glPopMatrix();



			// Casa
			//glPushMatrix();
			//glTranslatef(i, 0.0f, j);
			//glColor4ub(255, 255, 255, 255);
			//glEnableClientState(GL_VERTEX_ARRAY);
			//glVertexPointer(3, GL_FLOAT, 0, &this->vCasaVerticesVA.front());
			//glDrawElements(GL_TRIANGLES, vCasaIndexesVA.size(), GL_UNSIGNED_INT, &this->vCasaIndexesVA[0]);
			//glDisableClientState(GL_VERTEX_ARRAY);
			//glPopMatrix();
		}
	}*/

	/*
	// habilita testuras
	glEnable(GL_TEXTURE_2D);

	// Seta a textura atual


	glPushMatrix();
	glTranslatef(-5.0f, 0.0f, 0.0f);
	DrawCube();
	glEnd();
	glPopMatrix();

	pTextures->ApplyTexture(1);
	glPushMatrix();
	glTranslatef(5.0f, 0.0f, 0.0f);
	DrawPyramid();
	glEnd();
	glPopMatrix();


	glDisable(GL_TEXTURE_2D);
	*/

	// Ecercício 1

	glEnable(GL_TEXTURE_2D);

	pTextures->ApplyTexture(8);

	glPushMatrix();
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-21.0f, 0.0f, -21.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(21.0f, 0.0f, -21.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(21.0f, 0.0f, 21.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-21.0f, 0.0f, 21.0f);
	glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);


	glPushMatrix();
	DrawTree(0, 0, 0, 0.2, 5, 2);
	glPopMatrix();

	glPushMatrix();
	DrawTree(-5, 0, -5, 0.2, 5, 2);
	glPopMatrix();

	glPushMatrix();
	DrawTree(5, 0, -3, 0.7, 8, 3);
	glPopMatrix();

	glPushMatrix();
	// bug DrawTree(-7, 0, -3, 0.5, 4, 2);
	DrawTree(-7, 0, 3, 0.2, 5, 2);
	glPopMatrix();

	
	glPushMatrix();
	glTranslatef(-3.0f, 0.5 - 0.1, 1.5f);
	glRotatef(iAngle, 0.0f, 0.0f, 1.0f);
	DrawSnowMan();
	glPopMatrix();

	
	if (iAngle <= 45 && bState == false) {
		iAngle++;
		if (iAngle == 45) {
			bState = true;
		}
	}
	if (iAngle >= -45 && bState == true) {
		iAngle--;
		if (iAngle == -45) {
			bState = false;
		}
	}

	glDisable(GL_TEXTURE_2D);
	 
	// Fim Exercicio 1

	// Exercicio 2
	//glPushMatrix();
	//randomCube = rand() % 5;
	//int tempo = pTimer->GetTime() /1000;
	//if (tempo % 1 == 0) {
	//	if (randomCube == 1) {
	//		if (vector1 == 10) {

	//		}
	//		else {
	//			glTranslatef(0, vector1, 0);
	//			glColor3ub(rand() % 255, rand() % 255, rand() % 255);
	//			DrawCube();
	//			vector1++;
	//		}
	//	}
	//	else if (randomCube == 2) {
	//		if (vector2 == 10) {

	//		}
	//		else {
	//			glTranslatef(1, vector2, 0);
	//			glColor3ub(rand() % 255, rand() % 255, rand() % 255);
	//			DrawCube();
	//			vector2++;
	//		}
	//	}
	//	else if (randomCube == 3) {
	//		if (vector3 == 10) {

	//		}
	//		else {
	//			glTranslatef(2, vector3, 0);
	//			glColor3ub(rand() % 255, rand() % 255, rand() % 255);
	//			DrawCube();
	//			vector3++;
	//		}
	//	}
	//	else if (randomCube == 4) {
	//		if (vector4 == 10) {

	//		}
	//		else {
	//			glTranslatef(3, vector4, 0);
	//			glColor3ub(rand() % 255, rand() % 255, rand() % 255);
	//			DrawCube();
	//			vector4++;
	//		}
	//	}
	//	else {
	//		if (vector5 == 10) {

	//		}
	//		else {
	//			glTranslatef(4, vector5, 0);
	//			glColor3ub(rand() % 255, rand() % 255, rand() % 255);
	//			DrawCube();
	//			vector5++;
	//		}
	//	}
	//	glPopMatrix();


	//	if ((vector1 == 10) && (vector2 == 10) && (vector3 == 10) && (vector4 == 10) && (vector5 == 10)) {
	//		vector1 = 0;
	//		vector2 = 0;
	//		vector3 = 0;
	//		vector4 = 0;
	//		vector5 = 0;
	//	}
	//}

	// Fim Exercicio 2
	
	//// Exercício 3

	//glEnable(GL_TEXTURE_2D);

	//pTextures->ApplyTexture(2);

	//glPushMatrix();
	//glBegin(GL_QUADS);
	//glTexCoord2f(0.0f, 0.0f); glVertex3f(-21.0f, 0.0f, -21.0f);
	//glTexCoord2f(1.0f, 0.0f); glVertex3f(21.0f, 0.0f, -21.0f);
	//glTexCoord2f(1.0f, 1.0f); glVertex3f(21.0f, 0.0f, 21.0f);
	//glTexCoord2f(0.0f, 1.0f); glVertex3f(-21.0f, 0.0f, 21.0f);
	//glEnd();
	//glPopMatrix();
	//glDisable(GL_TEXTURE_2D);

	//// Habilitar o uso de texturas
	//glEnable(GL_TEXTURE_2D);

	//glPushMatrix();

	//// Frente
	//pTextures->ApplyTexture(5);
	//glBegin(GL_QUADS);
	//glTexCoord2f(0.0f, 0.0f); glVertex3f(-4, 0, 0);
	//glTexCoord2f(1.0f, 0.0f); glVertex3f(4, 0, 0);
	//glTexCoord2f(1.0f, 1.0f); glVertex3f(4, 4, 0);
	//glTexCoord2f(0.0f, 1.0f); glVertex3f(-4, 4, 0);
	//glEnd();

	//// Frente 2
	//pTextures->ApplyTexture(4);
	//glBegin(GL_QUADS);
	//glTexCoord2f(0.0f, 0.0f); glVertex3f(-4, 0, 0);
	//glTexCoord2f(1.0f, 0.0f); glVertex3f(-8, 0, 0);
	//glTexCoord2f(1.0f, 1.0f); glVertex3f(-8, 4, 0);
	//glTexCoord2f(0.0f, 1.0f); glVertex3f(-4, 4, 0);
	//glEnd();

	//// Esquerda
	//pTextures->ApplyTexture(4);
	//glBegin(GL_QUADS);
	//glTexCoord2f(0.0f, 0.0f); glVertex3f(-8, 0, 0);
	//glTexCoord2f(1.0f, 0.0f); glVertex3f(-8, 0, -4);
	//glTexCoord2f(1.0f, 1.0f); glVertex3f(-8, 4, -4);
	//glTexCoord2f(0.0f, 1.0f); glVertex3f(-8, 4, 0);
	//glEnd();

	//// Atrás
	//pTextures->ApplyTexture(3);
	//glBegin(GL_QUADS);
	//glTexCoord2f(0.0f, 0.0f); glVertex3f(-4, 0, -4);
	//glTexCoord2f(1.0f, 0.0f); glVertex3f(4, 0, -4);
	//glTexCoord2f(1.0f, 1.0f); glVertex3f(4, 4, -4);
	//glTexCoord2f(0.0f, 1.0f); glVertex3f(-4, 4, -4);
	//glEnd();

	//// Atrás 2
	//pTextures->ApplyTexture(3);
	//glBegin(GL_QUADS);
	//glTexCoord2f(0.0f, 0.0f); glVertex3f(-8, 0, -4);
	//glTexCoord2f(1.0f, 0.0f); glVertex3f(-4, 0, -4);
	//glTexCoord2f(1.0f, 1.0f); glVertex3f(-4, 4, -4);
	//glTexCoord2f(0.0f, 1.0f); glVertex3f(-8, 4, -4);
	//glEnd();

	//// Direita
	//pTextures->ApplyTexture(3);
	//glBegin(GL_QUADS);
	//glTexCoord2f(0.0f, 0.0f); glVertex3f(4, 0, 0);
	//glTexCoord2f(1.0f, 0.0f); glVertex3f(4, 0, -4);
	//glTexCoord2f(1.0f, 1.0f); glVertex3f(4, 4, -4);
	//glTexCoord2f(0.0f, 1.0f); glVertex3f(4, 4, 0);
	//glEnd();

	//// Cima
	//pTextures->ApplyTexture(3);
	//glBegin(GL_QUADS);
	//glTexCoord2f(0.0f, 0.0f); glVertex3f(-8, 4, 0);
	//glTexCoord2f(1.0f, 0.0f); glVertex3f(-8, 4, -4);
	//glTexCoord2f(1.0f, 1.0f); glVertex3f(4, 4, -4);
	//glTexCoord2f(0.0f, 1.0f); glVertex3f(4, 4, 0);
	//glEnd();

	//// Frente telhado
	//pTextures->ApplyTexture(6);
	//glBegin(GL_QUADS);
	//glTexCoord2f(0.0f, 0.0f); glVertex3f(-10, 3.5, 2);
	//glTexCoord2f(1.0f, 0.0f); glVertex3f(5, 3.5, 2);
	//glTexCoord2f(1.0f, 1.0f); glVertex3f(5, 5, -2);
	//glTexCoord2f(0.0f, 1.0f); glVertex3f(-10, 5, -2);
	//glEnd();

	//// Atras telhado
	//pTextures->ApplyTexture(6);
	//glBegin(GL_QUADS);
	//glTexCoord2f(0.0f, 0.0f); glVertex3f(-10, 3.5, -6);
	//glTexCoord2f(1.0f, 0.0f); glVertex3f(5, 3.5, -6);
	//glTexCoord2f(1.0f, 1.0f); glVertex3f(5, 5, -2);
	//glTexCoord2f(0.0f, 1.0f); glVertex3f(-10, 5, -2);
	//glEnd();

	//pTextures->ApplyTexture(3);
	//glBegin(GL_TRIANGLES);
	//// Telhado Esquerda
	//glTexCoord2f(0.0f, 0.0f); glVertex3f(-8, 4, 0);
	//glTexCoord2f(1.0f, 0.0f); glVertex3f(-8, 4, -4);
	//glTexCoord2f(1.0f, 1.0f); glVertex3f(-8, 5, -2);
	//// Telhado Direita
	//glTexCoord2f(0.0f, 0.0f); glVertex3f(4, 4, 0);
	//glTexCoord2f(1.0f, 0.0f); glVertex3f(4, 4, -4);
	//glTexCoord2f(1.0f, 1.0f); glVertex3f(4, 5, -2);
	//glEnd();
	//glDisable(GL_TEXTURE_2D);

	//glPopMatrix();

	//// Desabilitar o uso de texturas, se necessário
	//glDisable(GL_TEXTURE_2D);
	//glEnd();
	//glPopMatrix();

	//glEnable(GL_TEXTURE_2D);
	//glTranslatef(5.0f, 0.5f, 4.0f);
	//pTextures->ApplyTexture(0);
	//glPushMatrix();
	//DrawCube();
	//glPopMatrix();

	//glTranslatef(0.1f, 1.0f, -0.1f);
	//glRotatef(45, 0, 1, 0);
	//glPushMatrix();
	//DrawCube();
	//glPopMatrix();

	//glTranslatef(1.0f, 0.0f, 1.0f);
	//glRotatef(-45, 0, 1, 0);
	//glScalef(1.3, 3, 1.3);
	//glPushMatrix();
	//DrawCube();
	//glPopMatrix();

	//glDisable(GL_TEXTURE_2D);

	// Fim exercicio 3
	
	// Exercicio 4

	/*glEnable(GL_TEXTURE_2D);
	glColor3f(1, 1, 1);
	pTextures->ApplyTexture(7);
	glPushMatrix();
	glTranslatef(1.0f, 0.0f, 1.0f);
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < 204; i++)
	{
		
		glTexCoord2f(vCasaIndexes[i].t1, vCasaIndexes[i].t2); glVertex3f(vCasaIndexes[i].p1, vCasaIndexes[i].p2, vCasaIndexes[i].p3);

	}
	glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);*/

	// Fim exercicio 4










	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//                               DESENHA OS OBJETOS DA CENA (FIM)
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	fTimerPosY = pTimer->GetTime() / 1000.0f;
	fRenderPosY += 0.2f;

	// Impressão de texto na tela...
	// Muda para modo de projeção ortogonal 2D
	// OBS: Desabilite Texturas e Iluminação antes de entrar nesse modo de projeção
	OrthoMode(0, 0, WIDTH, HEIGHT);


	glPushMatrix();
	glTranslatef(0.0f, HEIGHT - 150, 0.0f);	// Move 1 unidade para dentro da tela (eixo Z)

	// Cor da fonte
	glColor3f(1.0f, 1.0f, 0.0f);


	glRasterPos2f(10.0f, 0.0f);	// Posicionando o texto na tela
	if (!bIsWireframe) {
		pTexto->glPrint("[TAB]  Modo LINE"); // Imprime texto na tela
	}
	else {
		pTexto->glPrint("[TAB]  Modo FILL");
	}


	//// Camera LookAt
	glRasterPos2f(10.0f, 40.0f);
	pTexto->glPrint("Player LookAt  : %f, %f, %f", pCamera->Forward[0], pCamera->Forward[1], pCamera->Forward[2]);

	//// Posição do Player
	glRasterPos2f(10.0f, 60.0f);
	pTexto->glPrint("Player Position: %f, %f, %f", pCamera->Position[0], pCamera->Position[1], pCamera->Position[2]);

	//// Imprime o FPS da aplicação e o Timer
	glRasterPos2f(10.0f, 80.0f);
	pTexto->glPrint("Frames-per-Second: %d ---- Timer: %.1f segundos", iFPS, (pTimer->GetTime() / 1000));

	glRasterPos2f(10.0f, 100.0f);
	pTexto->glPrint("fRot: %.1f ", fRotY);




	glPopMatrix();

	// Muda para modo de projeção perspectiva 3D
	PerspectiveMode();

	return true;
}




void CScene3::MouseMove(void) // Tratamento de movimento do mouse
{
	// Realiza os cálculos de rotação da visão do Player (através das coordenadas
	// X do mouse.
	POINT mousePos;
	int middleX = WIDTH >> 1;
	int middleY = HEIGHT >> 1;

	GetCursorPos(&mousePos);

	if ((mousePos.x == middleX) && (mousePos.y == middleY)) return;

	SetCursorPos(middleX, middleY);

	fDeltaX = (float)((middleX - mousePos.x)) / 10;
	fDeltaY = (float)((middleY - mousePos.y)) / 10;

	// Rotaciona apenas a câmera
	pCamera->rotateGlob(-fDeltaX, 0.0f, 1.0f, 0.0f);
	pCamera->rotateLoc(-fDeltaY, 1.0f, 0.0f, 0.0f);
}

void CScene3::KeyPressed(void) // Tratamento de teclas pressionadas
{

	// Verifica se a tecla 'W' foi pressionada e move o Player para frente
	if (GetKeyState('W') & 0x80)
	{
		pCamera->moveGlob(pCamera->Forward[0], pCamera->Forward[1], pCamera->Forward[2]);
	}
	// Verifica se a tecla 'S' foi pressionada e move o Player para tras
	else if (GetKeyState('S') & 0x80)
	{
		pCamera->moveGlob(-pCamera->Forward[0], -pCamera->Forward[1], -pCamera->Forward[2]);
	}
	// Verifica se a tecla 'A' foi pressionada e move o Player para esquerda
	else if (GetKeyState('A') & 0x80)
	{
		pCamera->moveGlob(-pCamera->Right[0], -pCamera->Right[1], -pCamera->Right[2]);
	}
	// Verifica se a tecla 'D' foi pressionada e move o Player para direira
	else if (GetKeyState('D') & 0x80)
	{
		pCamera->moveGlob(pCamera->Right[0], pCamera->Right[1], pCamera->Right[2]);
	}
	else if (GetKeyState('Q') & 0x80)
	{
		pCamera->moveGlob(0.0f, -pCamera->Up[1], 0.0f);
	}
	else if (GetKeyState('E') & 0x80)
	{
		pCamera->moveGlob(0.0f, pCamera->Up[1], 0.0f);
	}
	// Senão, interrompe movimento do Player
	else
	{
	}


	if (GetKeyState(VK_LEFT) & 0x80)
		fPosX -= 0.1f;
	if (GetKeyState(VK_RIGHT) & 0x80)
		fPosX += 0.1f;
	if (GetKeyState(VK_UP) & 0x80)
		fPosZ -= 0.1f;
	if (GetKeyState(VK_DOWN) & 0x80)
		fPosZ += 0.1f;
	if (GetKeyState(VK_PRIOR) & 0x80)
		fPosY += 0.1f;
	if (GetKeyState(VK_NEXT) & 0x80)
		fPosY -= 0.1f;


}

void CScene3::KeyDownPressed(WPARAM	wParam) // Tratamento de teclas pressionadas
{
	switch (wParam)
	{
	case VK_TAB:
		bIsWireframe = !bIsWireframe;
		break;

	case VK_SPACE:
		pTimer->Init();
		break;

	case VK_RETURN:
		break;

	}

}

//	Cria um grid horizontal ao longo dos eixos X e Z
void CScene3::Draw3DSGrid(float width, float length)
{

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(0.0f, 0.3f, 0.0f);
	glPushMatrix();
	for (float i = -width; i <= length; i += 1)
	{
		for (float j = -width; j <= length; j += 1)
		{
			// inicia o desenho das linhas
			glBegin(GL_QUADS);
			glNormal3f(0.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(i, 0.0f, j + 1);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(i + 1, 0.0f, j + 1);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(i + 1, 0.0f, j);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(i, 0.0f, j);
			glEnd();
		}
	}
	glPopMatrix();
	//glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}



void CScene3::DrawAxis()
{
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
	// Eixo X
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-1000.0f, 0.0f, 0.0f);
	glVertex3f(1000.0f, 0.0f, 0.0f);

	// Eixo Y
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 1000.0f, 0.0f);
	glVertex3f(0.0f, -1000.0f, 0.0f);

	// Eixo Z
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, 1000.0f);
	glVertex3f(0.0f, 0.0f, -1000.0f);
	glEnd();
	glPopMatrix();
}




void CScene3::DrawCube()
{
	glBegin(GL_QUADS);
	// face frente
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, -0.5f, 0.5f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.5f, -0.5f, 0.5f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.5f, 0.5f, 0.5f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f, 0.5f, 0.5f);

	// face trás
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.5f, -0.5f, -0.5f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.5f, -0.5f, -0.5f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.5f, 0.5f, -0.5f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.5f, 0.5f, -0.5f);

	// face direita
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.5f, -0.5f, 0.5f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.5f, -0.5f, -0.5f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.5f, 0.5f, -0.5f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.5f, 0.5f, 0.5f);


	// face esquerda
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, -0.5f, -0.5f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.5f, -0.5f, 0.5f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.5f, 0.5f, 0.5f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f, 0.5f, -0.5f);

	// face baixo
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, -0.5f, -0.5f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.5f, -0.5f, -0.5f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.5f, -0.5f, 0.5f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f, -0.5f, 0.5f);

	// face cima
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, 0.5f, 0.5f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.5f, 0.5f, 0.5f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.5f, 0.5f, -0.5f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f, 0.5f, -0.5f);

	glEnd();
}

void CScene3::RandomColor() {
	 red = rand() % 256; 
	 green = rand() % 256;
	 blue = rand() % 256;
}

void CScene3::DrawPyramid()
{
	glBegin(GL_TRIANGLES);

	// Face frente
	glTexCoord2f(0.023f, 0.1f); glVertex3f(-0.5f, -0.5f, 0.5f);
	glTexCoord2f(0.435f, 0.1f); glVertex3f(0.5f, -0.5f, 0.5f);
	glTexCoord2f(0.23f, 0.45f); glVertex3f(0.0f, 0.5f, 0.0f);

	// Face direita
	glTexCoord2f(0.023f, 0.55f); glVertex3f(0.5f, -0.5f, 0.5f);
	glTexCoord2f(0.435f, 0.55f); glVertex3f(0.5f, -0.5f, -0.5f);
	glTexCoord2f(0.23f, 0.895f); glVertex3f(0.0f, 0.5f, 0.0f);

	// Face esquerda
	glTexCoord2f(0.53f, 0.55f); glVertex3f(0.5f, -0.5f, -0.5f);
	glTexCoord2f(0.94f, 0.55f); glVertex3f(-0.5f, -0.5f, -0.5f);
	glTexCoord2f(0.73f, 0.89f); glVertex3f(0.0f, 0.5f, 0.0f);

	// Face trás
	glTexCoord2f(0.53f, 0.1f); glVertex3f(-0.5f, -0.5f, -0.5f);
	glTexCoord2f(0.94f, 0.1f); glVertex3f(-0.5f, -0.5f, 0.5f);
	glTexCoord2f(0.732f, 0.45f); glVertex3f(0.0f, 0.5f, 0.0f);
	glEnd();
}

void CScene3::DrawTree(float pX, float pY, float pZ, float eX, float eY, float eZ) {
	glPushMatrix();
	glTranslatef(pX, eY - 1, pZ);
	glColor3ub(181, 72, 0);
	auxSolidCylinder(eX, eY);

	glPushMatrix();
	glTranslatef(0, -eY / 2, 0);
	glRotatef(90, -1, 0, 0);
	glColor3ub(0, 181, 0);
	auxSolidCone(eZ, eY / 2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -eY / 4, 0);
	glRotatef(90, -1, 0, 0);
	glColor3ub(0, 181, 0);
	auxSolidCone(eZ, eY / 2);
	glPopMatrix();

	glPopMatrix();
}

void CScene3::DrawSnowMan() {
	float fAltura = 0.5;
	glPushMatrix();
	glColor3ub(255, 255, 255);
	auxSolidSphere(fAltura);


	glPushMatrix();
	glTranslatef(0, fAltura * 1.2, 0);
	auxSolidSphere(fAltura / 1.5);

	// Botoes
	glPushMatrix();
	glColor3ub(255, 0, 0);
	glTranslatef(0.0f, 0.0f, 0.33f);
	auxSolidSphere(0.03);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(255, 0, 0);
	glTranslatef(0.0f, 0.13f, 0.3f);
	auxSolidSphere(0.03);
	glPopMatrix();

	glPopMatrix();

	glPushMatrix();
	glColor3ub(255, 255, 255);
	glTranslatef(0, fAltura * 2.2, 0);
	auxSolidSphere(fAltura / 2.0);
	// Nariz
	glPushMatrix();
	glColor3ub(252, 121, 5);
	auxSolidCone(0.07, 0.5);
	glPopMatrix();

	// olhos
	glPushMatrix();
	glColor3ub(0, 0, 0);
	glTranslatef(0.12, 0.04, 0.2);
	auxSolidSphere(0.05);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(0, 0, 0);
	glTranslatef(-0.12, 0.04, 0.2);
	auxSolidSphere(0.05);
	glPopMatrix();
	// chapéu
	glPushMatrix();
	glColor3ub(30, 62, 247);
	glTranslatef(0.0, 0.2, 0.0);
	glRotatef(90, 1, 0, 0);
	auxSolidCone(0.3, 0.0);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(30, 62, 247);
	glTranslatef(0.0, -0.5, 0.0);
	auxSolidCylinder(0.2, 0.3);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(30, 62, 247);
	glTranslatef(0.0, 0.5, 0.0);
	glRotatef(90, 1, 0, 0);
	auxSolidCone(0.2, 0.0);
	glPopMatrix();

	glPopMatrix();

	glPopMatrix();
}