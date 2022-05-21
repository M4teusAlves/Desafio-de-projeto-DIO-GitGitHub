/* Autor: Mateus Alves
   Data: 21/05/2022
   e-mail: mateus.alves.desenvolvedor@gmail.com
   Descrição: Solicitar ao operador o sexo, o nome e as notas das provas parciais de um aluno (P1, P2, P3, P4), validar, processar
              e, considerando a média aritmética:
              a) se a média for inferior a 4, apresente como resultado “ALUNO REPROVADO”;
              b) se a média for superior ou igual a 6, apresente como resultado “ALUNO APROVADO”;
              c) se a média for entre 4 e 5,9, solicite os pontos obtidos na P5, validando-os, reprocesse ((Media Anterior + P5)
              / 2) e:
              c.1) se a média for inferior a 4, apresente como resultado “REPROVADO NA P5”;
              c.2) se a média for superior ou igual a 6, apresente “APROVADO NA P5”;
              c.3) se a média for entre 4 e 5,9, solicite os pontos obtidos na segunda época, reprocesse e:
              c.3.1) se a média for inferior a 6, apresente “REPROVADO NA SEG ÉPOCA”;
              c.3.2) se a média for superior ou igual a 6, apresente “APROVADO NA SEG ÉPOCA”;
              Observações:
              1. A nota não pode ser inferior a zero e muito menos superior a dez.
              2. O nome é obrigatório.
              3. O sexo deve ser considerado (m – Masculino) ou (f – Feminino).

              Implemente no exercício anterior um processo de repetição até que o sexo fornecido seja “x”, e apresente no final os
              seguintes valores:
              a) quantos alunos foram processados ao todo,
              b) quantos foram aprovados diretamente
              c) quantos foram reprovados diretamente
              d) quantos ficaram de P5
              e) quantos foram reprovados na P5
              f) quantos foram aprovados na P5
              g) quantos ficaram de segunda época
              h) quantos foram reprovados na segunda época.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <locale.h>

int main()
{
    /// Acentuação
    setlocale(LC_ALL, "Portuguese");

    /// Declaração e inicialização de variáveis
    float p1, p2, p3, p4, p5, p6, media;
    int total=0, ap_dir=0, rp_dir=0, fp5=0, ap_p5=0, rp_p5=0, fseg=0, rp_seg=0, ap_seg=0, qtd_ap=0, qtd_rp=0;
    char nome[60], sexo='m';

    while(sexo!='x')
    {
        ///Incializando algumas variáveis
        p1=p2=p3=p4=p5=p6=media=0;
        strcpy(nome,"");

        /// Recolhendo dados
        system("cls");
        printf("\n\nSexo do aluno(a) \nm - masculino\nf - Feminino \nx - Finalizar programa \nEscolha: ");
        fflush(stdin);
        scanf("%c",&sexo);

        // Validação sexo
        while(sexo!='m' && sexo!='f' && sexo!='x')
        {
            system("cls");
            printf("\n\nValor Inválido!\n Sexo do aluno(a) \nm - masculino \nx - Finalizar programa \nf - Feminino \nEscolha: ");
            fflush(stdin);
            scanf("%c",&sexo);
        }

        if(sexo!='x')
        {
            printf("\nNome do aluno: ");
            fflush(stdin);
            gets(nome);

            // Validação nome
            while(strcmp(nome,"")==0)
            {
                system("cls");
                printf("\n\nNome inválido! Digite novamente \nNome do aluno: ");
                fflush(stdin);
                gets(nome);
            }

            system("cls");
            printf("\n\nDigite a nota da P1: ");
            fflush(stdin);
            scanf("%f",&p1);

            // Validação P1
            while(p1<0 || p1>10)
            {
                system("cls");
                printf("\n\nNota inválida! \nDigite novamente a nota da P1: ");
                fflush(stdin);
                scanf("%f",&p1);
            }

            system("cls");
            printf("\n\nDigite a nota da P2: ");
            fflush(stdin);
            scanf("%f",&p2);

            // Validação P2
            while(p2<0 || p2>10)
            {
                system("cls");
                printf("\n\nNota inválida! \nDigite novamente a nota da P2: ");
                fflush(stdin);
                scanf("%f",&p2);
            }

            system("cls");
            printf("\n\nDigite a nota da P3: ");
            fflush(stdin);
            scanf("%f",&p3);

            // Validação P3
            while(p3<0 || p3>10)
            {
                system("cls");
                printf("\n\nNota inválida! \nDigite novamente a nota da P3: ");
                fflush(stdin);
                scanf("%f",&p3);
            }

            system("cls");
            printf("\n\nDigite a nota da P4: ");
            fflush(stdin);
            scanf("%f",&p4);

            // Validação P4
            while(p4<0 || p4>10)
            {
                system("cls");
                printf("\n\nNota inválida! \nDigite novamente a nota da P4: ");
                fflush(stdin);
                scanf("%f",&p4);
            }

            /// Processamento
            media=(p1+p2+p3+p4)/4;

            if(media<4)
            {
                system("cls");
                printf("\n\nALUNO REPROVADO \nMÉDIA: %.1f",media);
                getch();

                rp_dir++;
                qtd_rp++;
            }
            else if(media>=6)
            {
                system("cls");
                printf("\n\nALUNO APROVADO \nMÉDIA: %.1f",media);
                getch();

                ap_dir++;
                qtd_ap++;
            }
            else
            {
                system("cls");
                printf("\n\nDigite a nota da P5: ");
                fflush(stdin);
                scanf("%f",&p5);

                // Validação P5
                while(p5<0 || p5>10)
                {
                    system("cls");
                    printf("\n\nNota inválida! \nDigite novamente a nota da P5: ");
                    fflush(stdin);
                    scanf("%f",&p5);
                }

                media=(media+p5)/2;
                fp5++;

                if(media<4)
                {
                    system("cls");
                    printf("\n\nALUNO REPROVADO NA P5 \nMÉDIA: %.1f",media);
                    getch();

                    rp_p5++;
                    qtd_rp++;
                }
                else if(media>=6)
                {
                    system("cls");
                    printf("\n\nALUNO APROVADO NA P5 \nMÉDIA: %.1f",media);
                    getch();

                    ap_p5++;
                    qtd_ap++;
                }
                else
                {
                    system("cls");
                    printf("\n\nDigite a nota da SEGUNDA ÉPOCA: ");
                    fflush(stdin);
                    scanf("%f",&p6);

                    // Validação P6
                    while(p6<0 || p6>10)
                    {
                        system("cls");
                        printf("\n\nNota inválida! \nDigite novamente a nota da SEGUNDA ÉPOCA: ");
                        fflush(stdin);
                        scanf("%f",&p6);
                    }

                    media=(media+p6)/2;
                    fseg++;

                    if(media<6)
                    {
                        system("cls");
                        printf("\n\nALUNO REPROVADO NA SEG ÉPOCA \nMÉDIA: %.1f",media);
                        getch();

                        rp_seg++;
                        qtd_rp++;
                    }
                    else
                    {
                        system("cls");
                        printf("\n\nALUNO APROVADO NA SEG ÉPOCA \nMÉDIA: %.1f",media);
                        getch();

                        ap_seg++;
                        qtd_ap++;
                    }
                }
            }

            total++;
        }
    }

    /// Apresentação dos resultados
    if(total!=0)
    {
        system("cls");
        printf("\n\nQuantos alunos foram processados ao todo: %d",total);
        printf("\nQuantos foram aprovados diretamente: %d",ap_dir);
        printf("\nQuantos foram reprovados diretamente: %d",rp_dir);
        printf("\nQuantos ficaram de P5: %d",fp5);
        printf("\nQuantos foram reprovados na P5: %d",rp_p5);
        printf("\nQuantos foram aprovados na P5: %d",ap_p5);
        printf("\nQuantos ficaram de segunda época: %d",fseg);
        printf("\nQuantos foram reprovados na segunda época: %d",rp_seg);
        printf("\nQuantos foram aprovados na segunda época: %d",ap_seg);
        printf("\nTotal geral de aprovados: %d",qtd_ap);
        printf("\nTotal geral de reprovados: %d",qtd_rp);
    }
    else
    {
        system("cls");
        printf("\n\nNenhum aluno informado!");
    }

    /// Finalização
    printf("\n\n\nObrigado, Tchau!\n\n");
}
