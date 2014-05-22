let a20() = begin
    let a10 = Hashtbl.create 20 in
    let a11 = Hashtbl.create 20 in
    let a1 = Hashtbl.create 20 in
    let a2 = ref [] in
    begin try
	while true do
	  let a3 = read_line() in
	  let a4 = read_line() in
	  Hashtbl.add a1 a3 a4;
          Hashtbl.add a11 a4 a3;
	  if not (List.mem a3 !a2) then (a2 := !a2 @ [a3]);
	  if not (List.mem a4 !a2) then a2 := !a2 @ [a4];
	done
      with _-> () end;
    List.iter (fun a19 ->
	       begin try
        	   let a5 = Hashtbl.find_all a1 a19 in
		   Hashtbl.add a10 a19 (List.length a5);
	         with _ -> Hashtbl.add a10 a19 0 end;
	      ) !a2;
    let a21 a10 a6 = Hashtbl.find a10 a6 = 0 in
    let a7 = a21 a10 in
    let a9 = List.filter a7 !a2 in
    let a8 = List.sort (fun a16 a17 -> String.compare a16 a17) a9 in
    let rec a22 a9 a10 a11 a12 =
      match a9 with
      | [] -> a12
      | hd :: tl ->
	 let a13 = Hashtbl.find_all a11 hd in
	 List.iter (fun a19 ->
		    Hashtbl.add a10 a19 ((Hashtbl.find a10 a19) - 1);
		   ) a13;
	 let a14 = (List.filter (fun a19 -> Hashtbl.find a10 a19 = 0) a13) @ tl in
         let a15 = List.sort (fun a16 a17 -> String.compare a16 a17) a14 in
	 a22 a15 a10 a11 (a12 @ [hd]);
    in
    let a18 = a22 a8 a10 a11 []; in
    if List.length a18 = List.length !a2 then
      List.iter (fun a19 ->
       		 Printf.printf "%s\n" a19
		) a18
    else Printf.printf "cycle\n"
  end;;
  a20() ;;
