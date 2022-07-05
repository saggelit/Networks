clear; clc; clf;
a=load("net3kgamma2.0.txt");
b=load("net3kgamma2.0D.txt");
figure(1)
h=histogram(a(:,2))
title('Ιστόγραμμα κατανομής συνδέσεων k - γ=2.0')
xlabel('k')
ylabel('Πλήθος εμφάνισης κάθε σύνδεσης')

figure(2)
values=h.Values/length(a(:,2)); %y
counts=h.BinCounts;
c=(h.BinEdges+h.BinWidth/2);
centers=c(1:end-1); %x
loglog(centers,counts,'.')
title('Συνάρτηση Πυκνότητας Πιθανότητας - γ=2.0')
xlabel('log(k)')
ylabel('Πιθανότητα - log(P(k))')
hold on
p=polyfit((centers),(counts),1);
yfit=polyval(p,(centers));
plot((centers),counts)
legend({['y=',num2str(p(1)),'*x + ','(',num2str(p(2)),')']},'location','west');

%% Distribution
x=b(2:64,1);
y=b(2:64,2);
figure(3)
loglog(x,y,'*')
hold on
pp=polyfit(log(x),log(y),1); 
mm = pp(1);
bb = exp(pp(2));
fplot(@(x1) bb*x1.^mm,[x(1) x(end)])
title("Συνάρτηση Πυκνότητας Πιθανότητας - γ=2.0")
xlabel("Log(k)")
ylabel("Πιθανότητα - Log(P(k))")
legend(' ',['y=',num2str(pp(1)),'*x + ','(',num2str(pp(2)),')'],'Location','southwest');

