#include "stdafx.h"
#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;

/*** 
Author: Walysson Carlos dos Santos Oliveira
***/

// FUNCOES AUXILIARES
void mostrar(String nome, Mat img);
Mat umPixelTodaImg(Mat img, int valorPixel);
// QUANTIZAÇAO
Mat quantizarPiso(Mat image, int numeroDeBits);
Mat quantizarTeto(Mat image, int numeroDeBits);
// OPERACOES ARITMETCAS
Mat somar(Mat imgA, Mat imgB);
Mat subtrair(Mat imgA, Mat imgB);
Mat multiplicar(Mat imgA, Mat imgB);
Mat multiplicarEscalar(Mat imgA, float escalar);
Mat dividir(Mat imgA, Mat imgB);
// OPERACOES LOGICAS
Mat e(Mat imgA, Mat imgB);
Mat ou(Mat imgA, Mat imgB);
Mat xou(Mat imgA, Mat imgB);
Mat nao(Mat img);
// OPERACOES GEOMETRICAS
Mat translacao(Mat img, int linhas, int colunas);
Mat rotacao(Mat img, int angulo);
Mat escalar(Mat img, float escalarX, float escalarY);

int main()
{
	Mat imgLena = imread("lena-cinza.png", IMREAD_GRAYSCALE);
	Mat imgLenaRGB = imread("lena.jpg", IMREAD_COLOR);
	mostrar("imgLena", imgLenaRGB);
	//mostrar("quantizarPiso", quantizarPiso(imgLena, 2));
	//mostrar("quantizarTeto", quantizarTeto(imgLena, 2));
	Mat imgA = imread("A.png", WINDOW_NORMAL);
	//Mat imgB = imread("B.png", WINDOW_NORMAL);
	mostrar("imgA", imgA);
	//mostrar("imgB", imgB);
	//mostrar("somaAB", somar(imgA, imgB));
	//mostrar("subtracaoAB", subtrair(imgA, imgB));
	//mostrar("subtracaoBA", subtrair(imgB, imgA));
	//mostrar("multiplicarAB", multiplicar(imgA, imgB));
	//mostrar("multiplicarBA", multiplicar(imgB, imgA));
	//mostrar("dividirAB", dividir(imgA, imgB));
	//mostrar("dividirBA", dividir(imgB, imgA));
	//mostrar("andAB", e(imgA, imgB));
	//mostrar("orAB", ou(imgA, imgB));
	//mostrar("xorAB", xou(imgA, imgB));
	//mostrar("notA", nao(imgA));
	//mostrar("notB", nao(imgB));
	//mostrar("imgATrans15,15", translacao(imgA, 15, 15));
	//mostrar("imgATrans-15,-15", translacao(imgA, -15, -15));
	//mostrar("imgARota45", rotacao(imgLena, 45));
	//mostrar("imgARota90", rotacao(imgLena, 90));
	//mostrar("imgARota180", rotacao(imgLena, 180));
	//mostrar("LenaEsc1", escalar(imgLena, 1, 0.5));
	//mostrar("LenaEsc2", escalar(imgLena, 0.5, 1));

	waitKey(0);
	return 0;
}

void mostrar(String nome, Mat img) {
	namedWindow(nome, WINDOW_NORMAL);
	imshow(nome, img);
}

/*** ATIVIDADE 1  ***/
Mat quantizarPiso(Mat image, int numeroDeBits) {
	Mat img = image.clone();

	int niveis = pow(2, numeroDeBits);
	int tonsPorNivel = 256 / niveis;
	int valorDivisao = 0;
	int valorQuantizado = 0;
	for (int x = 0; x < img.rows; x++) {
		for (int y = 0; y < img.cols; y++) {
			valorDivisao = (img.at<uchar>(x, y) / tonsPorNivel);
			valorQuantizado = valorDivisao * tonsPorNivel;
			img.at<uchar>(x, y) = valorQuantizado;
		}
	}
	return img;
}

Mat quantizarTeto(Mat image, int numeroDeBits) {
	Mat img = image.clone();

	int niveis = pow(2, numeroDeBits);
	int tonsPorNivel = 256 / niveis;
	int valorDivisao = 0;
	int valorQuantizado = 0;
	for (int x = 0; x < img.rows; x++) {
		for (int y = 0; y < img.cols; y++) {
			valorDivisao = (img.at<uchar>(x, y) / tonsPorNivel);
			valorQuantizado = (valorDivisao * tonsPorNivel) + tonsPorNivel - 1;
			img.at<uchar>(x, y) = valorQuantizado;
		}
	}
	return img;
}

/*** ATIVIDADE 2 ***/
Mat somar(Mat imgA, Mat imgB) {
	Mat imgAB = imgA.clone();
	int tom = 0;
	for (int x = 0; x < imgAB.rows; x++) {
		for (int y = 0; y < imgAB.cols; y++) {
			tom = imgA.at<uchar>(x, y) + imgB.at<uchar>(x, y);

			if (tom > 255) {
				imgAB.at<uchar>(x, y) = 255;
			}
			else {
				imgAB.at<uchar>(x, y) = tom;
			}
		}
	}
	return imgAB;
}

Mat subtrair(Mat imgA, Mat imgB) {
	Mat imgAB = imgA.clone();
	int tom = 0;
	for (int x = 0; x < imgAB.rows; x++) {
		for (int y = 0; y < imgAB.cols; y++) {
			tom = imgA.at<uchar>(x, y) - imgB.at<uchar>(x, y);

			if (tom < 0) {
				imgAB.at<uchar>(x, y) = 0;
			}
			else {
				imgAB.at<uchar>(x, y) = tom;
			}
		}
	}
	return imgAB;
}

Mat multiplicar(Mat imgA, Mat imgB) {
	Mat imgAB = imgA.clone();
	int tom = 0;
	for (int x = 0; x < imgAB.rows; x++) {
		for (int y = 0; y < imgAB.cols; y++) {
			tom = imgA.at<uchar>(x, y) * imgB.at<uchar>(x, y);

			if (tom > 255) {
				imgAB.at<uchar>(x, y) = 255;
			}
			else {
				imgAB.at<uchar>(x, y) = tom;
			}
		}
	}
	return imgAB;
}

Mat multiplicarEscalar(Mat imgA, float escalar) {
	Mat imgAB = imgA.clone();
	int tom = 0;
	for (int x = 0; x < imgAB.rows; x++) {
		for (int y = 0; y < imgAB.cols; y++) {
			tom = imgA.at<uchar>(x, y) * escalar;

			if (tom > 255) {
				imgAB.at<uchar>(x, y) = 255;
			}
			else {
				imgAB.at<uchar>(x, y) = tom;
			}
		}
	}
	return imgAB;
}

Mat dividir(Mat imgA, Mat imgB) {
	Mat imgAB = imgA.clone();
	for (int x = 0; x < imgAB.rows; x++) {
		for (int y = 0; y < imgAB.cols; y++) {
			if (imgB.at<uchar>(x, y) == 0) {
				imgAB.at<uchar>(x, y) = 255;
				if (imgA.at<uchar>(x, y) == 0)
					imgAB.at<uchar>(x, y) = 0;
			}
			else {
				imgAB.at<uchar>(x, y) = imgA.at<uchar>(x, y) / imgB.at<uchar>(x, y);
			}
		}
	}
	return imgAB;
}

Mat e(Mat imgA, Mat imgB) {
	Mat imgAB = imgA.clone();
	for (int x = 0; x < imgAB.rows; x++) {
		for (int y = 0; y < imgAB.cols; y++) {
			if (imgA.at<uchar>(x, y) == 0 || imgB.at<uchar>(x, y) == 0) {
				imgAB.at<uchar>(x, y) = 0;
			}
			else {
				imgAB.at<uchar>(x, y) = 255;
			}
		}
	}
	return imgAB;
}

Mat ou(Mat imgA, Mat imgB) {
	Mat imgAB = imgA.clone();
	for (int x = 0; x < imgAB.rows; x++) {
		for (int y = 0; y < imgAB.cols; y++) {
			if (imgA.at<uchar>(x, y) == 255 || imgB.at<uchar>(x, y) == 255) {
				imgAB.at<uchar>(x, y) = 255;
			}
			else {
				imgAB.at<uchar>(x, y) = 0;
			}
		}
	}
	return imgAB;
}

Mat xou(Mat imgA, Mat imgB) {
	Mat imgAB = imgA.clone();
	for (int x = 0; x < imgAB.rows; x++) {
		for (int y = 0; y < imgAB.cols; y++) {
			if ((imgA.at<uchar>(x, y) == 0 && imgB.at<uchar>(x, y) == 0) || (imgA.at<uchar>(x, y) == 255 && imgB.at<uchar>(x, y) == 255)) {
				imgAB.at<uchar>(x, y) = 255;
			}
			else {
				imgAB.at<uchar>(x, y) = 0;
			}
		}
	}
	return imgAB;
}

Mat nao(Mat img) {
	Mat imgAB = img.clone();
	for (int x = 0; x < imgAB.rows; x++) {
		for (int y = 0; y < imgAB.cols; y++) {
			if (imgAB.at<uchar>(x, y) == 0) {
				imgAB.at<uchar>(x, y) = 255;
			}
			else {
				imgAB.at<uchar>(x, y) = 0;
			}
		}
	}
	return imgAB;
}

Mat umPixelTodaImg(Mat img, int valorPixel) {
	Mat imgZero = img.clone();
	for (int x = 0; x < imgZero.rows; x++) {
		for (int y = 0; y < imgZero.cols; y++) {
			imgZero.at<uchar>(x, y) = valorPixel;
		}
	}
	return imgZero;
}

Mat translacao(Mat img, int linhas, int colunas) {
	Mat imgTrans = umPixelTodaImg(img, 30);
	int novoX, novoY;

	for (int x = 0; x < img.rows; x++) {
		for (int y = 0; y < img.cols; y++) {
			novoX = x + linhas;
			novoY = y + colunas;
			if (novoX > 0 && novoY > 0 && novoX < imgTrans.rows && novoY < imgTrans.cols) {
				imgTrans.at<uchar>(novoX, novoY) = img.at<uchar>(x, y);
			}
		}
	}
	return imgTrans;
}

Mat rotacao(Mat img, int angulo) {
	Mat imgRota = umPixelTodaImg(img, 30);
	int novoXTranslacao, novoYTranslacao, novoXRotacao, novoYRotacao, novoX, novoY;
	int linhaCentral = img.rows / 2;
	int colunaCentral = img.cols / 2;

	for (int x = 0; x < img.rows; x++) {
		for (int y = 0; y < img.cols; y++) {
			// TRANSLACAO PARA POSICIONAR O CENTRO DA IMAGEM NA ORIGEM (0,0)
			novoXTranslacao = x - linhaCentral;
			novoYTranslacao = y - colunaCentral;
			// ROTACAO DA IMAGEM
			novoXRotacao = novoXTranslacao * cos(angulo) - novoYTranslacao * sin(angulo);
			novoYRotacao = novoXTranslacao * sin(angulo) + novoYTranslacao * cos(angulo);
			// TRANSLACAO PARA DEVOLVER A IMAGEM DA ORIGEM PARA O CENTRO
			novoX = novoXRotacao + linhaCentral;
			novoY = novoYRotacao + colunaCentral;

			if (novoX > 0 && novoY > 0 && novoX < imgRota.rows && novoY < imgRota.cols) {
				imgRota.at<uchar>(novoX, novoY) = img.at<uchar>(x, y);
			}
		}
	}
	return imgRota;
}

Mat escalar(Mat img, float escalarX, float escalarY) {
	Mat imgEsc = umPixelTodaImg(img, 30);
	int novoXTranslacao, novoYTranslacao, novoXEcs, novoYEcs, novoX, novoY;
	int linhaCentral = img.rows / 2;
	int colunaCentral = img.cols / 2;

	for (int x = 0; x < img.rows; x++) {
		for (int y = 0; y < img.cols; y++) {
			// TRANSLACAO PARA POSICIONAR O CENTRO DA IMAGEM NA ORIGEM (0,0)
			novoXTranslacao = x - linhaCentral;
			novoYTranslacao = y - colunaCentral;
			// ROTAO DA IMAGEM
			novoXEcs = novoXTranslacao * escalarX;
			novoYEcs = novoYTranslacao * escalarY;
			// TRANSLAO PARA DEVOLVER A IMAGEM DA ORIGEM PARA O CENTRO
			novoX = novoXEcs + linhaCentral;
			novoY = novoYEcs + colunaCentral;

			if (novoX > 0 && novoY > 0 && novoX < imgEsc.rows && novoY < imgEsc.cols) {
				imgEsc.at<uchar>(novoX, novoY) = img.at<uchar>(x, y);
			}
		}
	}
	return imgEsc;
}
