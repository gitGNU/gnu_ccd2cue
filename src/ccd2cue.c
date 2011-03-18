/*
  Copyright 2010, Bruno Félix Rezende Ribeiro
*/

/*
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/*
  Nome: ccd2cue
  Descrição: Um programa para conversão de arquivos descritores de imagem de CD's do formato CCD para o formato CUE.
  Versão: 0.1
  Licença: GPL 3.0
  Autor: Bruno Félix Rezende Ribeiro 
  E-mail: oitofelix@gmail.com
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE* ccd_fpt; // ponteiro para a entrada ccd.
FILE* cue_fpt; // ponteiro para a saída cue.
char* img_name; // nome do arquivo de imagem.

int argc;
char** argv;

// help
// Descrição: exibe a ajuda do programa e sai.

void help()
{
  printf(\
	 "\
Usage: ccd2cue -h | -v | -i imgfile [-o cuefile] [ccdfile]\n\
\t-h display this help message\n\
\t-v display version information\n\
\t-i use imgfile as image filename\n\
\t-o write output to cuefile\n\
"\
	 );

  exit(0);
}

// version
// Descrição: exibe a versão do programa e sai.

void version()
{
  puts("ccd2cue 0.1\nCompiled in " __DATE__ " at " __TIME__ "\nReport bugs to <oitofelix@gmail.com>");
  exit(0);
}

// check_arguments
// Descrição: checa os argumentos passados ao programa e toma as devidas providências.
// Nota: A checagem dos argumentos é orientada à quantidade deles.

void check_arguments(int argc, char* argv[])
{
  switch (argc-1) // Orienta a checagem à quantidade de argumentos
    {

      // Caso tenhamos um único argumento, só duas possibilidades são válidas, pedir ajuda ou verificar versão. Se nenhuma dessas for requisitada, considera-se a primeira.

    case 1: 
      if (!strcmp(argv[1], "-h")) help(); // O usuário pediu ajuda. Chamêmo-la.
      if (!strcmp(argv[1], "-v")) version(); // O usuário quer saber a versão. Informêmo-la.
      help(); // O usuário não sabe o que está fazendo! Vamos tentar ajudá-lo.

      // Caso sejam passados 2 argumentos, a única possibilidade válida é o usuário ter informado o nome do arquivo de imagem. Considera-se que o arquivo ccd será lido da entrada padrão e o cue escrito para a saída padrão.

    case 2:
      if (!strcmp(argv[1], "-i")) // Se o nome da imagem foi informado leiamos o ccd de "stdin" e escrevamos a conversão em cue para "stdout".
	{
	  img_name = argv[2];
	  ccd_fpt = stdin;
	  cue_fpt = stdout;
	  break;
	}
      help(); // O usuário informou incorretamente os argumentos. Vamos refrescar sua memória.

      // Para 3 argumentos a única possibilidade válida é o usuário ter informado o arquivo de imagem e a entrada ccd (um nome de arquivo ou "-" para "stdin"). Considera-se a saída como a padrão.

    case 3:
      if (!strcmp(argv[1], "-i")) // O usuário passou o argumento válido?
	{
  	  img_name = argv[2];
	  if (!strcmp(argv[3], "-")) ccd_fpt = stdin; // Verifica se usuário deseja ler de "stdin".
	  else if ((ccd_fpt = fopen(argv[3], "r")) == NULL) // Se o usuário quer ler de um arquivo, se possível ele é aberto, do contrário um erro é retornado.
	    {
	      perror("ccd2cue");
	      exit(-1);
	    }
	  cue_fpt = stdout; // A saída é necessariamente a padrão.
	  break;
	}
      help(); // O usuário está perdido. Sejamos gentis e vamos auxiliá-lo.

      // Para 4 argumentos a única possibilidade válida é o usuário ter informado o arquivo de imagem e a saída. Considera-se a entrada como a padrão.
 
    case 4:
      if (!strcmp(argv[1], "-i") && !strcmp(argv[3], "-o")) // O usuário fez direitinho?
	{
	  img_name = argv[2];
	  if (!strcmp(argv[4], "-")) cue_fpt = stdout; // Verifica se o usuário quer escrever para a saída padrão.
	  else if ((cue_fpt = fopen(argv[4], "w")) == NULL) //Se o usuário quer escrever para um arquivo, será que é possível abrí-lo para escrita? Se sim, o faz. Se não, retorna erro.
	    {
	      perror("ccd2cue");
	      exit(-1);
	    }
	  ccd_fpt = stdin; // A entrada é necessariamente a padrão.
	  break;
	}
      help(); // "help()" ajude-o ele não sabe o que faz!

      // Para 5 argumentos a única possibilidade válida é o usuário ter informado o arquivo de imagem a saída e a entrada.

    case 5:
      if (!strcmp(argv[1], "-i") && !strcmp(argv[3], "-o")) // Informou o arquivo de imagem e a saída?
	{
	  img_name = argv[2];
	  if (!strcmp(argv[4], "-")) cue_fpt = stdout; // Quer escrever na saída padrão?
	  else if ((cue_fpt = fopen(argv[4], "w")) == NULL) // Se quer escrever num arquivo, podemos abrí-lo para escrita?
	    {
	      perror("ccd2cue");
	      exit(-1);
	    }
	  if (!strcmp(argv[5], "-")) ccd_fpt = stdin; // Quer ler da entrada padrão?
  	  else if ((ccd_fpt = fopen(argv[5], "r")) == NULL) // Se quer ler dum arquivo, podemos abrí-lo para leitura?
	    {
	      perror("ccd2cue");
	      exit(-1);
	    }
	  break;
	}
      help(); // Os argumentos não fazem sentido. Sou um programa burro e dependo da colaboração do usuário. Vou colaborar para que ele colabore.

      // Para 0 argumentos, 6 ou mais, nada é válido. Ajuda nele.

    default:
      help();
    }
}

// file_convert
// Descrição: Realiza a conversão do arquivo

void file_convert()
{
  // Definições mágicas

#define MAX_LINE_SIZE 100 // Tamanho máximo em bytes a ser lido de cada linha do arquivo de entrada
#define FRAMES_PER_SECOND 75 // 1 segundo = 75 frames
#define SECONDS_PER_MINUTE 60 // 1 minuto = 60 segundos
#define FRAMES_PER_MINUTE (FRAMES_PER_SECOND*SECONDS_PER_MINUTE) // 1 minuto = 75*60 frames

  // Variáveis que armazenam número da faixa, tipo da faixa, índice de faixa e duração do índice. Assume-se que o número da primeira faixa é 1 se não for encontrada referência no arquivo de entrada.
  unsigned int track = 1, mode, index, minutes, seconds, frames;
  char line[MAX_LINE_SIZE];

  // Escreve na saída o nome do arquivo de imagem no formato cue.
  fprintf(cue_fpt, "FILE \"%s\" BINARY\n", img_name);

  // Inicia processo de conversão linha a linha até que o arquivo acabe.
  while (!feof(ccd_fpt))
    { 
      // Faz leitura duma linha do arquivo de origem e armazena em "line", mas se o arquivo acabou fgets retorna NULL e o processo termina.
      if (fgets(line, MAX_LINE_SIZE, ccd_fpt) == NULL) break;

      // Se a linha lida diz respeito à alguma faixa, armazena-se o número em "track".
      sscanf(line, "[TRACK %u]\r\n", &track);

      // Se a linha lida diz respeito ao tipo de faixa (dados ou áudio) armazena-se o tipo em "mode". Se "mode" for 0 considera-se faixa de áudio, senão faixa de dados.
      // Então escreve-se para a saída, no formato cue, o número da faixa (o último lido) e o seu tipo (dados ou áudio).
      if (sscanf(line, "MODE=%u\r\n", &mode)) fprintf(cue_fpt, mode ? " TRACK %u MODE2/2352\n" : " TRACK %u AUDIO\n", track);

      // Se a linha lida diz respeito ao índice da faixa, armazena-se o número do índice em "index" e sua duração em quadros em "frames". Faz-se então a conversão de quadros para tempo usual em minutos, segundos e quadros residuais segundo a seguinte equivalência: 1 segundo = 75 frames, 1 minuto = 60 segundos. Depois escreve-se para a saída o índice e sua duração em formato cue ("minutos:segundos:frames" - números de dois dígitos).
      if (sscanf(line, "INDEX %u=%u\r\n", &index, &frames))
	{
	  minutes = frames/FRAMES_PER_MINUTE;
	  seconds = frames/FRAMES_PER_SECOND - minutes*SECONDS_PER_MINUTE;
	  frames = frames - minutes*FRAMES_PER_MINUTE - seconds*FRAMES_PER_SECOND;
	  fprintf(cue_fpt, "  INDEX %u %02u:%02u:%02u\n", index, minutes, seconds, frames);  
	}
    }

  // Fecha os ponteiros de entrada ccd e saída cue e fim de conversão!
  fclose(ccd_fpt);
  fclose(cue_fpt);
}

int main(int argc, char* argv[])
{
  // Checa os argumentos e toma as devidas providências à respeito deles.
  check_arguments(argc, argv);

  // Chama a conversão de arquivo, dado que o programa não terminou no passo anterior chamando ajuda ou versão.
  file_convert();

  // Seja feliz com seu novo arquivo cue!
  return(0);
}
