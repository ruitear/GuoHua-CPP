file=dir('E:\OneDrive\liurui-doc\CCPR');
fileSize=size(file);
fileout=fopen('matlabList.txt','w');
%     \n一般会操作系统被翻译成"行的结束"，即LF(Line-Feed)
%     \r会被翻译成"回车"，即CR(Cariage-Return)
%       对于文本文件的新行，在UNIX上，一般用\n(LF)来表示，Mac上用\r(CR)来表示，
%       Windows上是用\n\r(CR-LF)来表示。  
for i=1:fileSize(1);
    if(file(i).isdir==0)
        fprintf(fileout,'%s\r\n',file(i).name); 
    end
end