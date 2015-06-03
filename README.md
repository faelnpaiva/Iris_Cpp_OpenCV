# Iris_Cpp_OpenCV
Iris detection using C++ and OpenCV 

Este é o código feito em opencv e C++ .
Ele processa e faz o reconhecimento da Iris , porém a distancia de HD não possui uma interface , ela print no terminal .
Após arrumar o código da camera para a raspberry pi capturar a imagem , este código será usado para o processamento e posteriormente reconhecimento ou não do individuo.


Para gerar o codigo a ser comparado, tem que colocar o nome da imagem em variables.cpp e deixar a imagem no mesmo folder que o executavel . Após gerar o codigo , manualmente coloque o código na main.cpp e mude para outra imagem em variables.cpp (ou deixe a mesma , HD=0.0 ) . O software fara a comparação do código que você gerou ( e alterou o nome na main) , gerará um código para a imagem que você alterou em variables e comparará .

É necessário que instale a biblioteca opencv (aqui foi a versão 2.4.9) e exporte a variavel de ambiente composta pelo path da build da biblioteca. Vários tutoriais são encontrados na internet , por exemplo ( https://www.youtube.com/watch?v=e_TQ9c3n_d8 ) . No caso do windows , consegui executar o .exe em Release utilizando o "Cygwin64 Terminal" , com o comando ./Iris.exe.
Caso você precise rodar o código no Ubuntu , é necessário re-compilar a biblioteca OpenCV ativando/desativando recursos que você queira . O CMAKE funciona muito bem .  Vários tutoriais são facilmente encontrado, por exemplo ( https://sites.google.com/a/computacao.ufcg.edu.br/lvc/aprendizado/opencv) .

Obrigado ao Fady Taher que me ajudou com o Gabor Filter , enviando seu código para eu corrigir e editar algumas coisas !
