let a1 = Hashtbl.create 100 in
    let a2 = ref "" in
    let a3 = ref "" in
    let a4 = ref [] in
    let a5 = ref 0 in
    let a6 = ref [] in
    let a7 = ref [] in
    let a8 = ref false in
    let a16 a11 a12 a9 =
      if List.length a12 == 0 then a11::a9 else a9
    in
    let a17 a10 a11 a12 =
      a4 := [];
      a4 := List.filter (fun a13 -> a13 <> a10) a12;
      Hashtbl.replace a1 a11 !a4;
    in
    try
      while true do
	a2 := read_line();
	a3 := read_line();
	if Hashtbl.mem a1 !a2 then
	  begin
	    a4 := Hashtbl.find a1 !a2;
	    a4 := !a3::!a4;
	    Hashtbl.replace a1 !a2 !a4
	  end
	else Hashtbl.add a1 !a2 [!a3];
	if Hashtbl.mem a1 !a3 then a4:=Hashtbl.find a1 !a3 else Hashtbl.add a1 !a3 []
      done
    with _ -> begin
	a5 := Hashtbl.length a1;
	while List.length !a6 < !a5 do
	  a7:=[];
	  a7:= Hashtbl.fold a16 a1 [];
	  a7 := List.sort (fun a14 a15 -> compare a14 a15) !a7;
	  if List.length !a7 == 0 then
	    begin
	      a8 := true;
	      a5 := List.length !a6;
	      print_endline "cycle";
	    end
	  else
	    begin
	      a6 := (List.hd !a7) :: !a6;
	      Hashtbl.remove a1 (List.hd !a7);
	      Hashtbl.iter (a17 (List.hd !a7)) a1;
	      if List.length !a6 == !a5 then
		begin
		  a6:=List.rev !a6;
		  List.iter print_endline !a6;
		end
	      else a5:=!a5;
	    end
	done
      end
