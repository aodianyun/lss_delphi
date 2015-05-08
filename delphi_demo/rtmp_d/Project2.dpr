program Project2;

uses
  ExceptionLog,
  Forms,
  publish in 'publish.pas' {Form1};

{$R *.res}

begin
  Application.Initialize;
  Application.CreateForm(TForm1, Form1);
  Application.Run;
end.
