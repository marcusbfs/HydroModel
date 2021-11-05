# HydroModel

Resolvedor de equações definidas pelo usuário, permitindo a estimativa de quaisquer
variáveis. Desenvolvido principalmente para auxiliar no projeto de hidrociclones.

## Utilização

Para usar a interface gráfica, baixe o arquivo _HydroModel_winx64.zip_ disponível na
[página de releases](https://github.com/marcusbfs/HydroModel/releases) e descompacte-o.

Feito isto, execute o programa _HydroModelsGUI.exe_, que é a interface gráfica por onde
o usuário ira interagir.

Com o programa aberto, vá em "Open > File", e selecione "exemplo_de_entrada.txt", que
está na pasta descompactada. Este arquivo se trata de um exemplo, onde nele estão
implementadas algumas correlações clássicas no campo de ciclones e hidrociclones.

Após carregado o arquivo, vá em "Run > Run" ou aperte CTRL+R para ler o arquivo, extrair
as equações e resolve-las. Os resultados obtidos estarão na aba "Formatted output" para
rápida visualização.


## Dependências

- [wxWidgets](https://www.wxwidgets.org/): biblioteca para a criação de componentes
  gráficos.
- [antlr](https://www.antlr.org/): biblioteca para ler e processar textos estruturados.
  Neste projeto, a biblioteca serve para transformar as equações informadas por texto em
  uma árvore binária, que é capaz de expressar uma função matemática de modo
  sistematizado.


## Contato

Qualquer dúvida sobre a utilização ou sobre o código, e também sugestões de melhoria ou
funcionalidade, sinta-se livre para entrar em contato :)
