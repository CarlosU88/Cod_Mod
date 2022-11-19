#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <ctime>
#include <cmath>
using namespace std;

//---Definición clase nodo-----
class nodo{
    friend class lista_enlazada;
    private:
        long int dato;
        nodo *sig;
        nodo *ant;
    public:
        nodo(const long int d){
            dato = d;
            sig=NULL;
            ant=NULL;
        }

        long int getdato() const {
            return dato;
        }

};
//------------------------------

//---Definición clase lista-----
    class lista_enlazada{
    private:
        nodo *inicio_lista;
        nodo *fin_lista;
        nodo *get_nuevo_nodo(long int d){
            return new nodo(d);
        }
        unsigned long int Nnodos;
    public:
        //---Verificar si la lista esta vacia---
        bool lista_vacia(){
            return inicio_lista==NULL;
        }
        //-------------------------------
        //--- Numero de nodos en la lista ---------
        unsigned long int getNnodos(){
            return Nnodos;
        }
        //-----------------------------------------
        nodo *getinicio(){return inicio_lista;}
        nodo *getfin(){return fin_lista;}
        //---Insertar nodo al inicio de la lista ---
        void insertarAlFrente(const long valor) // inserta un nodo en la
		{                                       // parte frontal de la lista
			nodo *nuevoNodo = get_nuevo_nodo(valor);

			if (lista_vacia()){
				inicio_lista = fin_lista = nuevoNodo;
				Nnodos++;
			}
			else
			{
				nuevoNodo->sig = inicio_lista;
				inicio_lista = nuevoNodo;
				Nnodos++;
			}
		}
        //------------------------------------------
        //---Insertar nodo al final de la lista---
        void insertarAlFinal(const long int valor){
			nodo *nuevoNodo = get_nuevo_nodo(valor);
			if (lista_vacia()){
				inicio_lista = fin_lista = nuevoNodo;
				Nnodos++;}
			else
			{
				fin_lista->sig = nuevoNodo;
				nuevoNodo->ant = fin_lista;
				fin_lista = nuevoNodo;
				Nnodos++;
			}
		}
		//-----------------------------------------

        //--- Ordenamiento por algoritmo burbuja ---
        void Ordenamiento_Burbuja(){
            nodo *temp=inicio_lista;
            nodo *temp2=fin_lista;
            long int valor_temp=0;
            while(temp2!=inicio_lista){
                while(temp->sig!=NULL){
                    if(temp->dato>temp->sig->dato){
                       valor_temp = temp->sig->dato;
                       temp->sig->dato =temp->dato;
                       temp->dato = valor_temp;
                    }
                    temp = temp->sig;
                }
                temp2 = temp2->ant;
                temp = inicio_lista;
            }
        }
        //--------------------------------------------
        //--- Ordenamiento por algoritmo de selección---
        void Ordenamiento_Seleccion(){
            nodo *temp = inicio_lista;
            nodo *temp2 = inicio_lista;
            long int valor_temp=0;
            while(temp!=NULL){
                while(temp2!=NULL){
                    if(temp->dato>temp2->dato){
                        valor_temp = temp2->dato;
                        temp2->dato = temp->dato;
                        temp->dato = valor_temp;
                    }
                 temp2 = temp2->sig;
                }
                temp = temp->sig;
                temp2 = temp;
            }
        }
        //----------------------------------------------
        void Ordenamiento_Insercion(){
                nodo *temp1 = inicio_lista;
                inicio_lista = inicio_lista->sig;
                temp1->sig = NULL;
                nodo *temp2 = temp1;
                nodo *temp3 = temp1;
                nodo *temp4 = NULL;
                while(inicio_lista!=NULL){
                    if(inicio_lista->dato<=temp2->dato){
                        temp1 = inicio_lista;
                        inicio_lista=inicio_lista->sig;
                        temp1->sig = NULL; temp1->ant=NULL;

                        temp2->ant = temp1; temp1->sig=temp2;
                        temp2 = temp1;
                    }else if(inicio_lista->dato>=temp3->dato){
                        temp1 = inicio_lista;
                        inicio_lista=inicio_lista->sig;
                        temp1->sig = NULL; temp1->ant=NULL;

                        temp3->sig = temp1; temp1->ant = temp3;
                        temp3 = temp1;
                    }else{
                        if(inicio_lista!=NULL){
                            temp4 = temp2;
                        while(inicio_lista->dato>temp4->dato){
                            temp4=temp4->sig;
                        }
                        temp1 = inicio_lista;
                        inicio_lista=inicio_lista->sig;
                        temp1->sig = NULL; temp1->ant=NULL;

                        temp4->ant->sig = temp1;
                        temp1->ant = temp4->ant;
                        temp4->ant = temp1;
                        temp1->sig = temp4;
                        }

                    }

                    //inicio_lista=inicio_lista->sig;


                }
                inicio_lista = temp2; fin_lista = temp3;
            }
        //----------------------------------------------
        //--- Ordenamiento Quicksort -------------------
        void Ordenamiento_Quicksort(nodo *izq, nodo *der){
               if(izq!=der){
                    nodo *temp1=izq,*temp2=der,*piv=izq;
                    long int num=0;
                    izq = izq->sig;
                    while(izq!=der){
                        while(izq->dato<=piv->dato && izq!=der ){izq=izq->sig;}
                        while(der->dato>piv->dato && izq!=der){der=der->ant;}
                        if(izq!=der){
                            num = izq->dato;
                            izq->dato = der->dato;
                            der->dato = num;
                        }
                    }
                    if(piv->dato > der->dato){
                        num = der->dato;
                        der->dato = piv->dato;
                        piv->dato = num;
                    }
                    if(der->ant != NULL){Ordenamiento_Quicksort(temp1,der->ant);}
                    if(der->sig != NULL){Ordenamiento_Quicksort(der,temp2);}
               }
        }
        //----------------------------------------------
        void BuscarMin(nodo *inicio, nodo *fin){
            nodo *temp =inicio;
            long int val_temp = 0;
            if(inicio!=fin){
                while(temp!=fin->sig){
                    if(temp->dato<inicio->dato){
                        val_temp = temp->dato;
                        temp->dato = inicio->dato;
                        inicio->dato = val_temp;
                    }
                    temp=temp->sig;
                }
            }
        }
        //----------------------------------------------
        //--- Ordenamiento Mergesort (Crear Particion) ------------
        void Ordenamiento_Mergesort_1(nodo *inicio, nodo *fin){
                if(inicio->sig==fin){
                    BuscarMin(inicio,fin);
                }else if(inicio!=fin){
                    nodo *temp1 = inicio, *temp2=fin;
                    while(temp2 != temp1 && temp1->sig!=temp2 && temp2->ant!=temp1){
                        if(temp1->sig!=temp2 ){temp1 = temp1->sig;}
                        if(temp2->ant!=temp1){temp2 = temp2->ant;}
                    }
                        while(inicio!=temp1){BuscarMin(inicio,temp1); inicio=inicio->sig;}
                        while(temp2!=fin){BuscarMin(temp2,fin);temp2=temp2->sig;}

                }
        }
        //----------------------------------------------------------
        //--- Ordenamiento Mergesort (Unir partición) --------------
         void Ordenamiento_Mergesort(nodo *inicio, nodo *fin){
                Ordenamiento_Mergesort_1(inicio,fin);
                nodo *temp1 = inicio, *temp2=fin,*temp3=NULL,*temp4=NULL,*temp5=NULL;
                while(temp2 != temp1 && temp1->sig!=temp2){
                    if(temp1->sig!=temp2){temp1 = temp1->sig;}
                    if(temp2->ant!=temp1){temp2 = temp2->ant;}
                } temp1->sig=NULL; temp2->ant=NULL;
                while(inicio!=NULL && temp2!=NULL){
                        if(inicio->dato<temp2->dato){
                            temp5=inicio;inicio=inicio->sig;temp5->sig=NULL;//inicio->ant = NULL;
                        }else{
                            temp5=temp2;temp2=temp2->sig;temp5->sig=NULL;//temp2->ant=NULL;
                        }
                        if(temp4==NULL && temp3==NULL){
                            temp3=temp4=temp5;
                        }else{
                            temp4->sig=temp5;temp5->ant=temp4;temp4=temp5;
                        }
                }

                if(inicio != NULL && temp2 == NULL){
                    while(inicio!=NULL){
                            temp5=inicio;inicio=inicio->sig;temp5->sig=NULL;//inicio->ant = NULL;
                        if(temp4==NULL && temp3==NULL){
                            temp3=temp4=temp5;
                        }else{
                            temp4->sig=temp5;temp5->ant=temp4;temp4=temp5;
                        }
                    }
                }
                if(inicio == NULL && temp2 != NULL){
                    while(temp2!=NULL){
                        temp5=temp2;temp2=temp2->sig;temp5->sig=NULL;//temp1->ant=NULL;
                        if(temp4==NULL && temp3==NULL){
                            temp3=temp4=temp5;
                        }else{
                            temp4->sig=temp5;temp5->ant=temp4;temp4=temp5;
                        }
                    }
                }
            inicio_lista = temp3;fin_lista = temp4;
        }
        //----------------------------------------------------------
        //--- Busqueda secuencial --------------------------------
        void Busqueda_Secuencial(long int d){
            nodo *temp = inicio_lista;
            while(temp!= NULL){
                if(temp->dato == d){
                    cout << "Busqueda finalizada - Dato encontrado."<<endl;
                    break;
                }
                temp = temp->sig;
            }
            if(temp==NULL){cout << "Busqueda finalizada - Dato NO encontrado."<<endl;}
        }
        //--------------------------------------------------------
        nodo *previo_busq_bin(nodo *inicio,nodo *fin){
                nodo *temp1 = inicio, *temp2=fin;
                    while(temp2 != temp1 && temp1->sig!=temp2 && temp2->ant!=temp1){
                        if(temp1->sig!=temp2 ){temp1 = temp1->sig;}
                        if(temp2->ant!=temp1){temp2 = temp2->ant;}
                    }
                return temp1;
        }
        void Busqueda_binaria(nodo *temp, long int d){
            if(temp == NULL){
                cout << "Busqueda finalizada - Dato NO encontrado."<<endl;
            }else if(temp->dato == d){
                cout << "Busqueda finalizada - Dato encontrado."<<endl;
            }else{
                if(temp->dato<d){ Busqueda_binaria(temp->sig,d);}
                if(temp->dato>d){Busqueda_binaria(temp->ant,d);}
            }
        }
        //---Imprimir elementos en la lista-------------
        void imprimir_lista(){
			if( lista_vacia() )
			{
				cout << endl << "Lista esta vacia"<< endl;
				return;
			}

			nodo *actual=inicio_lista;

			cout << "La lista es:\n ";

			while( actual != NULL)
			{
				cout << actual->dato << " -> ";
				actual = actual->sig;
			}

			cout << "NULL\n\n";
		}
		//----------------------------------------

        //---Constructor-----------------
        lista_enlazada(){
            inicio_lista=NULL;
            fin_lista=NULL;
            Nnodos=0;
        }
        //-------------------------------
        //---Destructor------------------
        ~lista_enlazada(){
            if( !lista_vacia() )
                {
                    nodo *actual = inicio_lista;
                    nodo *temp;
                    while(actual!=NULL)
                    {
                        temp=actual;
                        actual = actual->sig;
                        delete temp;
                    }
                }
                cout << endl <<"Lista Vacia..." << endl;
        }
        //-------------------------------
    };
    //-----------------------------------------------
int main(){
    srand(time(NULL));
    lista_enlazada listas[6];
    int n=50000;
    unsigned t0, t1;
    double time=0;
    int num=0;
    cout<<"------------------------------------------------"<<endl;
    cout << "Creando listas..." << endl;
    t0=clock(); //Inicio del cronómetro.
    for(int i=0;i<n;i++){
            num = 1 + rand() % (10001 - 1);
            listas[0].insertarAlFinal(num);
            listas[1].insertarAlFinal(num);
            listas[2].insertarAlFinal(num);
            listas[3].insertarAlFinal(num);
            listas[4].insertarAlFinal(num);
            listas[5].insertarAlFinal(num);
    }
    t1 = clock();// Fin de cronómetro.
    cout << "Listas creadas..." << endl;
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time <<" seg."<< endl;
    cout<<"------------------------------------------------"<<endl;
    cout << "Ordenamiento Burbuja - Lista - 1:"<<endl;
    t0=clock();
    listas[0].Ordenamiento_Burbuja();
    t1=clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time <<" seg."<<endl;
    cout<<"------------------------------------------------"<<endl;
    cout << "Ordenamiento Seleccion - Lista - 2:"<<endl;
    t0=clock();
    listas[1].Ordenamiento_Seleccion();
    t1=clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time <<" seg."<< endl;
    cout<<"------------------------------------------------"<<endl;
    cout << "Ordenamiento Insercion - Lista - 3:"<<endl;
    t0=clock();
    listas[2].Ordenamiento_Insercion();
    t1=clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time <<" seg."<< endl;
    cout<<"------------------------------------------------"<<endl;
    cout << "Ordenamiento Quicksort - Lista - 4:"<<endl;
    t0=clock();
    listas[3].Ordenamiento_Quicksort(listas[3].getinicio(),listas[3].getfin());
    t1=clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time <<" seg."<< endl;
    cout<<"------------------------------------------------"<<endl;
    cout << "Ordenamiento Mergesort - Lista - 5:"<<endl;
    t0=clock();
    listas[4].Ordenamiento_Mergesort(listas[4].getinicio(),listas[4].getfin());
    t1=clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time <<" seg."<< endl;
    cout<<"------------------------------------------------"<<endl;
    cout << "Busqueda Secuencial - Lista - 6:"<<endl;num = 1 + rand() % (10001 - 1);
    cout << "Se buscara el valor: "<< num<<endl;
    cout << " - Lista sin ordenar - "<<endl;
    t0=clock();
    listas[5].Busqueda_Secuencial(num);
    t1=clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time <<" seg."<< endl;
    cout<<"------------------------------------------------"<<endl;
    cout << " - Lista ordenada - "<<endl;
    listas[5].Ordenamiento_Quicksort(listas[5].getinicio(),listas[5].getfin());
    t0=clock();
    listas[5].Busqueda_Secuencial(num);
    t1=clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time <<" seg."<< endl;
    cout<<"-----------------------------------------------"<<endl;
    cout << "Busqueda Binaria - Lista - 6:"<<endl;
    cout << " - Lista ordenada - busqueda binaria - "<<endl;
    nodo *temp = listas[5].previo_busq_bin(listas[5].getinicio(),listas[5].getfin());
    t0=clock();
    listas[5].Busqueda_binaria(temp,num);
    t1=clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time <<" seg."<< endl;
    cout<<"-----------------------------------------------"<<endl;
    return 0;
}
