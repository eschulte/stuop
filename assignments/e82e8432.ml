let rec a17 a8 a1 a10 =
  if a10 >= List.length !a1 then -1
  else if a10 < 0 then -1
  else if a8 = List.nth !a1 a10 then a10
  else a17 a8 a1 (a10+1)
;;
let rec a18 a8 a1 a2 a4 = begin
    if a2 >= List.length !a1 then 0
    else if a2 < 0 then 0
    else if a8 = List.nth !a1 a2 then ( 1 +
 	                                  a18 a8 a1 (a2 + 2) a4 )
    else a18 a8 a1 (a2 + 2) a4
  end ;;
let rec a19 a8 a1 a2 a3 a4 a6= begin
    if a2 >= List.length !a1 then []
    else if a2 < 0 then []
    else if a3 >= List.length !a1 then []
    else if a8 = List.nth !a1 a2 then (
      a17 (List.nth !a1 a3) a6 0 ::
 	a19 a8 a1 (a2 + 2) (a3 + 2) a4 a6)
    else a19 a8 a1 (a2 + 2) (a3 + 2)a4 a6
  end ;;
let a20 () = begin
    let a5 = ref [] in
    try
      while true do
        a5 := (read_line ()) :: !a5
      done
    with _ -> begin
        let a6 = ref [] in
        List.iter( fun a7 ->
                   if not( List.exists(fun a8 -> a8 = a7) !a6 )
                   then a6 := a7 :: !a6) !a5;
        let rec a21 a10 =
          if a10 >= List.length !a6 then []
          else  a18 (List.nth !a6 a10) a5 1 2
      	        :: a21 (a10 + 1)
        in
        let a9 = a21 0 in
        let rec a22 a10 =
          if a10 >= List.length !a6 then []
 	  else a19 (List.nth !a6 a10) a5 0 1 2 a6
	       :: a22 (a10 + 1)
        in
        let a11 = a22 0 in
        let a14 = ref [] in
        let a12 = ref [] in
        let a13 = Array.make (List.length a9) 0 in
        for a10 = 0 to List.length a9 - 1 do
          Array.set a13 a10 (List.nth a9 a10);
   	  if List.nth a9 a10 == 0
	  then a14 := List.nth !a6 a10 :: !a14
        done;
        let a14 = ref (List.sort(fun a15 a16 -> compare a15 a16) !a14) in
        while List.length !a14 > 0 do
          let n = List.nth !a14 0 in
          a12 := n :: !a12;
          a14 := List.filter(fun a8 -> not(a8 = n)) !a14;
          let index = a17 n a6 0 in
          List.iter( fun a7 ->
	             Array.set a13 a7 ((Array.get a13 a7) - 1)
	           ) (List.nth a11 index);
          List.iter( fun a7 ->
	             if (Array.get a13 a7) = 0 then a14 := List.nth !a6 a7 :: !a14
	           ) (List.nth a11 index);
          a14 := List.sort(fun a15 a16 -> compare a15 a16) !a14;
        done;
        let valid = ref true in
        Array.iter (fun a7 -> if a7 > 0 then valid := false ) a13;
        if !valid then List.iter print_endline (List.rev !a12);
        if not !valid then Printf.printf "cycle\n";
      end;
  end;;
  a20();;
