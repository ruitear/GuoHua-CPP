file=dir('E:\OneDrive\liurui-doc\CCPR');
fileSize=size(file);
fileout=fopen('matlabList.txt','w');
%     \nһ������ϵͳ�������"�еĽ���"����LF(Line-Feed)
%     \r�ᱻ�����"�س�"����CR(Cariage-Return)
%       �����ı��ļ������У���UNIX�ϣ�һ����\n(LF)����ʾ��Mac����\r(CR)����ʾ��
%       Windows������\n\r(CR-LF)����ʾ��  
for i=1:fileSize(1);
    if(file(i).isdir==0)
        fprintf(fileout,'%s\r\n',file(i).name); 
    end
end