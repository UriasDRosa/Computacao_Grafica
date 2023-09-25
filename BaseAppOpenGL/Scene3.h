#pragma once
#include "SceneBaseClass.h"
#include "CTexture.h"
#include "CTimer.h"
#include "CTexto.h"
#include "CCamera.h"
#include "VertexData.h"
#include <glm/glm.hpp>
#include <vector>

class CScene3 : public CSceneBaseClass
{
public:
	CScene3();
	~CScene3(void);


	virtual void MouseMove(void);					// Tratamento de movimento do mouse
	virtual void KeyPressed(void);					// Tratamento de teclas pressionadas
	virtual void KeyDownPressed(WPARAM	wParam);	// Tratamento de teclas pressionadas
	virtual int DrawGLScene(void);					// Fun��o que desenha a cena

	void Draw3DSGrid(float width, float length);
	void DrawAxis();

	void DrawCube();
	void RandomColor();
	void DrawPyramid();
	void DrawTree(float pX, float pY, float pZ, float eX, float eY, float eZ);
	void DrawSnowMan();

private:

	bool	keys[256];		// Array usado para rotinas do teclado
	bool	active;			// Window Active Flag Set To TRUE By Default
	bool	fullscreen;		// Exibir janela em modo fullscreem (TRUE) ou em janela (FALSE)


	CCamera* pCamera;	// Gerencia c�mera OpenGL
	float fDeltaY;				// Rota��o da c�mera OpenGL no eixo Y
	float fDeltaX;				// Rota��o da c�mera OpenGL no eixo X

	CTexto* pTexto;	// Objeto que gerencia texto
	CTexture* pTextures;	// Objeto que gerencia texturas
	CTimer* pTimer;	// Objeto que gerencia o timer


	int		iFPS;			// FPS and FPS Counter
	int		iFrames;		// FPS and FPS Counter
	DWORD	ulLastFPS;		// FPS and FPS Counter
	char	szTitle[256];	// FPS and FPS Counter


	bool bIsWireframe;	// Modos Wireframe/Solid
	bool bIsCameraFPS;	// Ativa modo de camera First Person Shooter (true) ou Third Person Shooter (false)

	float fRenderPosY;
	float fTimerPosY;

	float fRotY;

	int iAngle;

	bool bState;

	float fPosX;
	float fPosY;
	float fPosZ;

	int randomCube;

	int vector1;
	int vector2;
	int vector3;
	int vector4;
	int vector5;

	int red;
	int green;
	int blue;

	unsigned char R;
	unsigned char G;
	unsigned char B;


	CColor3 faceColor[38];


	CIndex5 vCasaIndexes[204] = {
	{7.34, 11.26, -2.34,0.73,  0.58},
	{-7.34, 11.26, -2.34,0.30, 0.58},
	{-7.34, 11.26, 2.34,0.30,  0.44},
	{-7.34, 11.26, 2.34,0.30,  0.44},
	{7.34, 11.26, 2.34,0.73,   0.44},
	{7.34, 11.26, -2.34,0.73,  0.58},
	{10.48, 7.46, -5.48,0.50,  0.22},
	{10.48, 7.46, 5.48,0.34,   0.22},
	{10.48, 0.00, 5.48,0.34,   0.11},
	{10.48, 0.00, 5.48,0.34,   0.11},
	{10.48, 0.00, -5.48,0.50,  0.11},
	{10.48, 7.46, -5.48,0.50,  0.22},
	{10.48, 7.46, -5.48,0.50,  0.22},
	{10.48, 0.00, -5.48,0.50,  0.11},
	{-10.48, 0.00, -5.48,0.82, 0.11},
	{-10.48, 0.00, -5.48,0.82, 0.11},
	{-10.48, 7.46, -5.48,0.82, 0.22},
	{10.48, 7.46, -5.48,0.50,  0.22},
	{-10.48, 7.46, 5.48,0.98,  0.22},
	{-10.48, 7.46, -5.48,0.82, 0.22},
	{-10.48, 0.00, -5.48,0.82, 0.11},
	{-10.48, 0.00, -5.48,0.82, 0.11},
	{-10.48, 0.00, 5.48,0.98,  0.11},
	{-10.48, 7.46, 5.48,0.98,  0.22},
	{-0.41, 1.43, 4.89,0.59,   0.85},
	{-0.41, 1.43, 5.48,0.59,   0.84},
	{2.37, 1.43, 5.48,0.67,    0.84},
	{2.37, 1.43, 5.48,0.67,    0.84},
	{2.37, 1.43, 4.89,0.67,    0.85},
	{-0.41, 1.43, 4.89,0.59,   0.85},
	{2.37, 4.66, 5.48,0.76,    0.84},
	{2.37, 4.66, 4.89,0.76,    0.85},
	{2.37, 1.43, 4.89,0.67,    0.85},
	{2.37, 1.43, 4.89,0.67,    0.85},
	{2.37, 1.43, 5.48,0.67,    0.84},
	{2.37, 4.66, 5.48,0.76,    0.84},
	{-0.41, 4.66, 5.48,0.84,   0.84},
	{-0.41, 4.66, 4.89,0.84,   0.85},
	{2.37, 4.66, 4.89,0.76,    0.85},
	{2.37, 4.66, 4.89,0.76,    0.85},
	{2.37, 4.66, 5.48,0.76,    0.84},
	{-0.41, 4.66, 5.48,0.84,   0.84},
	{-0.41, 4.66, 5.48,0.50,   0.84},
	{-0.41, 1.43, 5.48,0.59,   0.84},
	{-0.41, 1.43, 4.89,0.59,   0.85},
	{-0.41, 1.43, 4.89,0.59,   0.85},
	{-0.41, 4.66, 4.89,0.50,   0.85},
	{-0.41, 4.66, 5.48,0.50,   0.84},
	{4.45, 4.66, 4.89,0.75,  0.89},
	{7.24, 4.66, 4.89,0.67,  0.89},
	{7.24, 4.66, 5.48,0.67,  0.88},
	{7.24, 4.66, 5.48,0.67,  0.88},
	{4.45, 4.66, 5.48,0.75,  0.88},
	{4.45, 4.66, 4.89,0.75,  0.89},
	{4.45, 4.66, 5.48,0.75,  0.88},
	{4.45, 1.43, 5.48,0.84,  0.88},
	{4.45, 1.43, 4.89,0.84,  0.89},
	{4.45, 1.43, 4.89,0.84,  0.89},
	{4.45, 4.66, 4.89,0.75,  0.89},
	{4.45, 4.66, 5.48,0.75,  0.88},
	{4.45, 1.43, 5.48,0.50,  0.88},
	{7.24, 1.43, 5.48,0.58,  0.88},
	{7.24, 1.43, 4.89,0.58,  0.89},
	{7.24, 1.43, 4.89,0.58,  0.89},
	{4.45, 1.43, 4.89,0.50,  0.89},
	{4.45, 1.43, 5.48,0.50,  0.88},
	{7.24, 1.43, 4.89,0.58,  0.89},
	{7.24, 1.43, 5.48,0.58,  0.88},
	{7.24, 4.66, 5.48,0.67,  0.88},
	{7.24, 4.66, 5.48,0.67,  0.88},
	{7.24, 4.66, 4.89,0.67,  0.89},
	{7.24, 1.43, 4.89,0.58,  0.89},
	{-3.30, 0.18, 5.48,0.51, 0.94},
	{-3.30, 0.18, 4.67,0.51, 0.96},
	{-8.35, 0.18, 4.67,0.37, 0.96},
	{-8.35, 0.18, 4.67,0.37, 0.96},
	{-8.35, 0.18, 5.48,0.37, 0.94},
	{-3.30, 0.18, 5.48,0.51, 0.94},
	{-3.30, 6.03, 5.48,0.67, 0.94},
	{-3.30, 6.03, 4.67,0.67, 0.96},
	{-3.30, 0.18, 4.67,0.51, 0.96},
	{-3.30, 0.18, 4.67,0.51, 0.96},
	{-3.30, 0.18, 5.48,0.51, 0.94},
	{-3.30, 6.03, 5.48,0.67, 0.94},
	{-8.35, 6.03, 5.48,0.82, 0.94},
	{-8.35, 6.03, 4.67,0.82, 0.96},
	{-3.30, 6.03, 4.67,0.67, 0.96},
	{-3.30, 6.03, 4.67,0.67, 0.96},
	{-3.30, 6.03, 5.48,0.67, 0.94},
	{-8.35, 6.03, 5.48,0.82, 0.94},
	{-8.35, 0.18, 4.67,0.98, 0.96},
	{-8.35, 6.03, 4.67,0.82, 0.96},
	{-8.35, 6.03, 5.48,0.82, 0.94},
	{-8.35, 6.03, 5.48,0.82, 0.94},
	{-8.35, 0.18, 5.48,0.98, 0.94},
	{-8.35, 0.18, 4.67,0.98, 0.96},
	{-10.48, 7.46, 5.48,0.03,0.22},
	{-3.30, 6.03, 5.48,0.13, 0.20},
	{4.45, 4.66, 5.48,0.25,  0.18},
	{-10.48, 7.46, 5.48,0.03,0.22},
	{4.45, 4.66, 5.48,0.25,  0.18},
	{7.24, 4.66, 5.48,0.29,  0.18},
	{10.48, 7.46, 5.48,0.34, 0.22},
	{-10.48, 7.46, 5.48, 0.03, 0.22},
	{ 7.24, 4.66, 5.48,0.29,  0.18 },
	{ 10.48, 7.46, 5.48,0.34, 0.22 },
	{ 7.24, 4.66, 5.48,0.29,  0.18 },
	{ 7.24, 1.43, 5.48,0.29,  0.13 },
	{ 10.48, 0.00, 5.48,0.34, 0.11 },
	{ 10.48, 7.46, 5.48,0.34, 0.22 },
	{ 7.24, 1.43, 5.48,0.29,  0.13 },
	{ 10.48, 0.00, 5.48,0.34, 0.11 },
	{ 7.24, 1.43, 5.48,0.29,  0.13 },
	{ 4.45, 1.43, 5.48,0.25,  0.13 },
	{ 4.45, 1.43, 5.48,0.25,  0.13 },
	{ 4.45, 4.66, 5.48,0.25,  0.18 },
	{ 2.37, 4.66, 5.48,0.22,  0.18 },
	{ 4.45, 1.43, 5.48,0.25,  0.13 },
	{ 2.37, 4.66, 5.48,0.22,  0.18 },
	{ 2.37, 1.43, 5.48,0.22,  0.13 },
	{ 10.48, 0.00, 5.48,0.34, 0.11 },
	{ 4.45, 1.43, 5.48,0.25,  0.13 },
	{ 2.37, 1.43, 5.48,0.22,  0.13 },
	{ 10.48, 0.00, 5.48,0.34, 0.11 },
	{ 2.37, 1.43, 5.48,0.22,  0.13 },
	{ -0.41, 1.43, 5.48,0.18, 0.13 },
	{ 2.37, 4.66, 5.48,0.22,  0.18 },
	{ 4.45, 4.66, 5.48,0.25,  0.18 },
	{ -3.30, 6.03, 5.48,0.13, 0.20 },
	{ -0.41, 4.66, 5.48,0.18, 0.18 },
	{ 2.37, 4.66, 5.48,0.22,  0.18 },
	{ -3.30, 6.03, 5.48,0.13, 0.20 },
	{ -0.41, 1.43, 5.48,0.18, 0.13 },
	{ -0.41, 4.66, 5.48,0.18, 0.18 },
	{ -3.30, 6.03, 5.48,0.13, 0.20 },
	{ -0.41, 1.43, 5.48,0.18, 0.13 },
	{ -3.30, 6.03, 5.48,0.13, 0.20 },
	{ -3.30, 0.18, 5.48,0.13, 0.12 },
	{ 10.48, 0.00, 5.48,0.34, 0.11 },
	{ -0.41, 1.43, 5.48,0.18, 0.13 },
	{ -3.30, 0.18, 5.48,0.13, 0.12 },
	{ 10.48, 0.00, 5.48,0.34, 0.11 },
	{ -3.30, 0.18, 5.48,0.13, 0.12 },
	{ -8.35, 0.18, 5.48,0.06, 0.12 },
	{ -8.35, 6.03, 5.48,0.06, 0.20 },
	{ -3.30, 6.03, 5.48,0.13, 0.20 },
	{ -10.48, 7.46, 5.48,0.03,0.22 },
	{ -8.35, 0.18, 5.48,0.06, 0.12 },
	{ -8.35, 6.03, 5.48,0.06, 0.20 },
	{ -10.48, 7.46, 5.48,0.03,0.22 },
	{ -8.35, 0.18, 5.48,0.06, 0.12 },
	{ -10.48, 7.46, 5.48,0.03,0.22 },
	{ -10.48, 0.00, 5.48,0.03,0.11 },
	{ 10.48, 0.00, 5.48,0.34, 0.11 },
	{ -8.35, 0.18, 5.48,0.06, 0.12 },
	{ -10.48, 0.00, 5.48,0.03,0.11 },
	{ -10.48, 7.46, 5.48,0.04,0.97 },
	{ 10.48, 7.46, 5.48,0.32, 0.97 },
	{ 11.70, 7.02, 6.12,0.34, 0.98 },
	{ 11.70, 7.02, 6.12,0.34, 0.98 },
	{ -11.70, 7.02, 6.12,0.03,0.98 },
	{ -10.48, 7.46, 5.48,0.04,0.97 },
	{ 10.48, 7.46, 5.48,0.32, 0.97 },
	{ 10.48, 7.46, -5.48,0.32,0.82 },
	{ 11.70, 7.02, -6.12,0.34,0.81 },
	{ 11.70, 7.02, -6.12,0.34,0.81 },
	{ 11.70, 7.02, 6.12,0.34, 0.98 },
	{ 10.48, 7.46, 5.48,0.32, 0.97 },
	{ 10.48, 7.46, -5.48,0.32,0.82 },
	{ -10.48, 7.46,-5.48,0.04,0.82 },
	{ -11.70, 7.02,-6.12,0.03,0.81 },
	{ -11.70, 7.02,-6.12,0.03,0.81 },
	{ 11.70, 7.02, -6.12,0.34,0.81 },
	{ 10.48, 7.46, -5.48,0.32,0.82 },
	{ -10.48, 7.46,-5.48,0.04,0.82 },
	{ -10.48, 7.46, 5.48,0.04,0.97 },
	{ -11.70, 7.02, 6.12,0.03,0.98 },
	{ -11.70, 7.02, 6.12,0.03,0.98 },
	{ -11.70, 7.02,-6.12,0.03,0.81 },
	{ -10.48, 7.46,-5.48,0.04,0.82 },
	{ -11.70, 7.02, 6.12,0.17,0.32 },
	{ 11.70, 7.02, 6.12,0.86, 0.32 },
	{ 7.34, 11.26, 2.34,0.73, 0.44 },
	{ 7.34, 11.26, 2.34,0.73, 0.44 },
	{ -7.34, 11.26, 2.34,0.30,0.44 },
	{ -11.70, 7.02, 6.12,0.17,0.32 },
	{ 11.70, 7.02, 6.12,0.86, 0.32 },
	{ 11.70, 7.02, -6.12,0.86,0.70 },
	{ 7.34, 11.26, -2.34,0.73,0.58 },
	{ 7.34, 11.26, -2.34,0.73,0.58 },
	{ 7.34, 11.26, 2.34,0.73, 0.44 },
	{ 11.70, 7.02, 6.12,0.86, 0.32 },
	{ 11.70, 7.02, -6.12,0.86,0.70 },
	{ -11.70, 7.02,-6.12,0.17,0.70 },
	{ -7.34, 11.26,-2.34,0.30,0.58 },
	{ -7.34, 11.26,-2.34,0.30,0.58 },
	{ 7.34, 11.26, -2.34,0.73,0.58 },
	{ 11.70, 7.02, -6.12,0.86,0.70 },
	{ -11.70, 7.02,-6.12,0.17,0.70 },
	{ -11.70, 7.02, 6.12,0.17,0.32 },
	{ -7.34, 11.26, 2.34,0.30,0.44 },
	{ -7.34, 11.26, 2.34,0.30,0.44 },
	{ -7.34, 11.26,-2.34,0.30,0.58 },
	{ -11.70, 7.02,-6.12,0.17,0.70 },
	};
	
};