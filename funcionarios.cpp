#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<locale.h>
#include<fstream>
using namespace std;
	struct funcionario{
	char nome[50]; 
	char setor[20];
	int idade;
	float salario;
	int codigo;
	int op;
struct funcionario *prox, *ant;
}*prim, *ult, *aux;


		void inclusao(char nomeV[], int idadeV, int codV, char setorV[], float salarioV);
		void listagem();
		void exclusao(int codV);
		void alteracao(int opV,int codV);
		void gerartext();
		
main(){
	char nomeM[50], setorM[20];
	int idadeM, codM, op, op2;
	float salarioM;
	setlocale(LC_ALL,"portuguese");
	do{	cout<<endl;
		cout<<"escolha umas das opções seguintes:"<<endl;
		cout<<endl;
		cout<<"[1]incluir funcionario"<<endl;
		cout<<"[2]listar funcionarios"<<endl;
		cout<<"[3]Alterar"<<endl;		
		cout<<"[4]Excluir"<<endl;
		cout<<"[5]Gerar relatório .text"<<endl;
		cout<<"[6] sair"<<endl;
		cout<<endl;
		cout<<"digite o numero da opção escolhida: ";
		cin>>op;
		fflush(stdin);
			if(op==1){
				cout<<endl;
			cout<<"Digite o nome do funcionario: ";
			gets(nomeM);
			fflush(stdin);
			cout<<endl;
			cout<<"Digite idade do funcionario: ";
			cin>>idadeM;
			fflush(stdin);
				cout<<endl;
			cout<<"Digite código funcionario: ";
			cin>>codM;
			fflush(stdin);
				cout<<endl;
			cout<<"Digite setor funcionario: ";
			gets(setorM);
			fflush(stdin);
				cout<<endl;
			cout<<"Digite salário funcionario:";
			cin>>salarioM;
			fflush(stdin);
			inclusao(nomeM,idadeM,codM,setorM,salarioM);
		}
				else if(op==2)
					listagem();
						else if (op==3){
							cout<<"O que irá ser alterado ?"<<endl;
							cout<<"[1]salario"<<endl;
							cout<<"[2]idade"<<endl;
							cout<<"[3]setor"<<endl;
							cout<<"escolha umas das opções:";
							cin>>op2;
							fflush(stdin);
							cout<<"digite codigo do \funcionario:";
							cin>>codM;
							fflush(stdin);
							alteracao(op2,codM);
						}
								else if(op==4){
								cout<<"escolhas umas das opções abaixo"<<endl;
								cout<<"[1]excluir apenas um funcionario específico"<<endl;
								cout<<"[2]excluir todos os funcionarios"<<endl;
								cout<<"opção: ";
								cin>>op2;
									fflush(stdin);
									cout<<endl;
									if(op2==1){
										cout<<"Digite codigo do funcionario: ";
										cin>>codM;
										fflush(stdin);
										exclusao(codM);
									}
									else if(op2==2){
										aux=prim;
										while(aux){
											aux->ant=NULL;
											prim=aux->prox;
											if(aux==ult){
												prim=ult=NULL;
											}
											free(aux);
											aux=prim;
											
										}
										cout<<"exclusão bem sucedida!"<<endl;
									}
							}
												else if(op==5){
														gerartext();
															cout<<"arquivo criado";
								
													}
															else if(op!=6)
																cout<<"codigo invalido:"<<endl;
	}while(op!=6);
}
					void inclusao(char nomeV[], int idadeV, int codV, char setorV[], float salarioV){
						aux=(struct funcionario*)malloc(sizeof(struct funcionario));
						if(!prim){
							prim=aux;
							prim->ant=NULL;
						}
						else{
							ult->prox = aux;
							aux->ant = ult;
						}
						ult=aux;
						strcpy(ult -> nome,nomeV);
						ult->idade=idadeV;
						ult->codigo=codV;
						strcpy(ult->setor,setorV);
						ult->salario=salarioV;
						ult->prox=NULL;
						cout<<"funcionario incluido com sucesso!"<<endl;
						cout<<endl;
					}
					void listagem(){
						aux = prim;
						while(aux){
							cout<<endl;
							cout<<"funcionario código: "<<aux->codigo<<endl;
							cout<<"Nome: ";
							puts(aux->nome);
							cout<<"idade : "<<aux->idade<<endl;
							cout<<"setor: ";
							puts(aux->setor);
							cout<<"Salário: "<<aux->salario<<endl;
							aux= aux->prox;
						}
					}
								
					void alteracao(int opV,int codV){
									int found =0;
									aux=prim;
										while(aux && !found){
											if(aux->codigo == codV){
												if(opV==1){
													cout<<"Digite novo salario: ";
													cin>>aux->salario;
													fflush(stdin);
														cout<<endl;
													cout<<"Alteração bem sucedida!";
												}
												else if(opV==2){
													cout<<"Digite a idade: ";
													cin>>aux->idade;
														fflush(stdin);
															cout<<endl;
													cout<<"Alteração bem sucedida!"<<endl;
												}
												else{
													cout<<"Digite novo setor: ";
													gets(aux->setor);
														fflush(stdin);
														cout<<endl;
													cout<<"Alteração bem sucedida!"<<endl;
												}
												found=1;
											}
											else {
											aux=aux->prox;}
											
										}
										if(!found)
										cout<<"codigo invalido"<<endl;
										
										
									}
					void exclusao(int codV){
										int found = 0;
										aux=prim;
										while(aux && !found){
											if(aux->codigo == codV){
												if(aux == prim){
													if(aux == ult){
														prim=NULL;
														ult=NULL;
													}
													else{
														prim = prim->prox;
														prim->ant=NULL;
													}
													
												}
												else if(aux == ult){
													ult=ult->ant;
													ult->prox=NULL;
												}
												else{
												aux->prox->ant=aux->ant;
												aux->ant->prox=aux->prox;
												}
												found=1;
												free(aux);
											}
											else{
												aux=aux->prox;
											}
										}
										if(!found){
										cout<<"codigo invalido!!!"<<endl;
										cout<<endl;
									}
										else{
										cout<<"exclusão realizada com sucesso"<<endl;
										cout<<endl;
									}
									}
									
					void gerartext(){
							aux = prim;	
 								ofstream MyFile("ctest.txt");
								MyFile<<"<---RELATÓRIO---> \n \n";
								
						while(aux){
						
							MyFile<<"\n ------------------------------ \n"
							<<"Código: "<<aux->codigo
							<<"\n Nome: "<<aux->nome<<"\n Idade:"<<aux->idade
							<<"\n Setor:"<<aux->setor<<"\n Salário"<<aux->salario;
							aux= aux->prox;
						   }
								
 								MyFile.close();
 								
										
									}
							
