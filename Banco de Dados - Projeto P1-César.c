#include <stdio.h>
float horaextra(int horas, float valor) // fun��o para calcular hora extra
{
    return horas*valor;

}
float salariobruto(float grat, float sala, float medico, float hextra, float vtrans) //fun��o pra calcular salario bruto
{
    return grat+sala+medico+hextra+vtrans;
}
float fgts(float sal) //fun��o pra calcular fgts
{
    return ((sal*8)/100);
}
main()
{
    //ENTRADA
    int n,i, j,k;
    printf("\tDIGITE QUANTOS FUNCION�RIOS DESEJA CADASTRAR\n");
    scanf("%d", &n);
    float salariobase[n],vale[n], svale=0,vhextra[n],shextra=0, auxmedico[n],smedico=0, grati[n],sgrati=0,total=0,aux,aux1,aux2,sfgts=0;
    int matricula[n], nhextra[n] ;
    char nome[n][50], setor [n][50];
    for(j=0;j<n;j++)
    {
        i=j+1;
        printf("DIGITE O N�MERO DE MATR�CULA DO FUNCION�RIO %d\n", i);
        scanf("%d", &matricula[j]);
        printf("DIGITE O NOME DO FUNCION�RIO %d\n", i);
        getchar();
        scanf("%s", &nome[j]);
        printf("DIGITE O SETOR DE LOTA��O DO FUNION�RIO %d\n", i);
        getchar();
        scanf("%s", &setor[j]);
        printf("DIGITE O SAL�RIO BASE DO FUNION�RIO %d\n", i);
        scanf("%f", &salariobase[j]);
        printf("DIGITE O VALOR DO VALE-TRANSPORTE DO FUNION�RIO %d\n", i);
        scanf("%f", &vale[j]);
        svale= svale +vale[j];
        printf("DIGITE A QUANTIDADE DE HORAS EXTRAS REALIZADAS PELO FUNION�RIO %d\n", i);
        scanf("%d", &nhextra[j]);
        printf("DIGITE O VALOR DAS HORAS EXTRAS REALIZADAS PELO FUNION�RIO %d\n", i);
        scanf("%f", &vhextra[j]);
        printf("DIGITE O VALOR DO AUX�LIO-SA�DE RECEBIDO PELO FUNION�RIO %d\n", i);
        scanf("%f", &auxmedico[j]);
        smedico = smedico + auxmedico[j];
        printf("DIGITE O VALOR DA GRATIFICA��O RECEBIDA PELO FUNION�RIO %d\n", i);
        scanf("%f", &grati[j]);
        sgrati = sgrati + grati [j];
        printf("\n");
    }
    for(j=0;j<n;j++)
    {
        k=j+1;
        printf("\tDESPESA COM O FUNCION�RIO %s MATR�CULA %d LOTADO NO(A) %s\n\n", nome[j], matricula[j], setor[j]);
        aux=horaextra(nhextra[j],vhextra[j]);
        shextra = shextra +aux;
        printf("HORA EXTRA R$ %.2f\n", aux);
        aux1= salariobruto(grati[j],salariobase[j],auxmedico[j], aux, vale[j]);
        printf("SAL�RIO BRUTO R$ %.2f\n", aux1);
        aux2=fgts(salariobase[j]);
        sfgts=sfgts+ aux2;
        printf("FGTS R$ %.2f\n", aux2);
        printf("DESPESA TOTAL COM O FUNCION�RIO R$ %.2f\n", aux1+aux2);
        total= total + (aux1+aux2);
    }
    printf("\tDESPESA TOTAL\n");
    printf("DESPESA TOTAL COM HORA-EXTRA R$ %.2f\n", shextra);
    printf("DESPESA TOTAL COM VALE-TRANSPORTE R$ %.2f\n", svale);
    printf("DESPESA TOTAL COM AUX�LIO-SA�DE R$ %.2f\n", smedico);
    printf("DESPESA TOTAL COM GRATIFICA��ES R$ %.2f\n", sgrati);
    printf("DESPESA TOTAL COM FGTS R$ %2.f\n\n", sfgts);
    printf("\tDESPESA TOTAL R$ %.2f\n", total +sfgts);



return 0;
}
