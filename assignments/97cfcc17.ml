let a13 () =
  let a1 = 30 in
  Hashtbl.create a1
;;
let a14 () =
  let a2 = ref [] in begin
                    try
                      while true do
                        a2 := (read_line ()) :: !a2
                      done
                    with End_of_file -> ()
                  end;
                     !a2
;;
let a15 (a2: string list) : (string, string) Hashtbl.t =
  let rec a16 a2 a3 = match a2 with
    | [] -> a3
    | fs :: snd :: rest -> begin
                           Hashtbl.add a3 fs snd;
                           a16 rest a3
                         end
    | _ -> raise (Failure "expect even number of lines")
  in
  a16 a2 (a13 ())
;;
let a17
      (a3: ('a, 'b) Hashtbl.t) : ('a, int) Hashtbl.t * int =
  let a6 = a13 () in
  let a18 (a10: string) (a11: string) = begin
      if not (Hashtbl.mem a6 a10) then
        Hashtbl.add a6 a10 0;
      if (Hashtbl.mem a6 a11) then
        let a7 = Hashtbl.find a6 a11 in
        Hashtbl.replace a6 a11 (a7+1)
      else Hashtbl.add a6 a11 1
    end in
  Hashtbl.iter a18 a3;
  a6, (Hashtbl.length a6)
;;
let a19 (a3: ('a, 'b) Hashtbl.t) =
  let a4 = ref [] in
  let a6, a5 = a17 a3 in
  let a20 a6 =
    Hashtbl.fold (fun a11 a7 a8 -> if a7 == 0 then a11 :: a8 else a8) a6 []
  in
  let a9 = ref (a20 a6) in begin
                          a9 := List.sort compare !a9;
                          while List.length !a9 > 0 do
                            let a10 = List.hd !a9 in
                            a9 := List.tl !a9;
                            a4 := !a4 @ [a10];
                            let a21 a11 = begin
                                let a12 = (Hashtbl.find a6 a11) - 1 in
                                Hashtbl.replace a6 a11 a12;
                                if a12 = 0 then a9 := a11 :: !a9
                              end in
                            List.iter a21 (Hashtbl.find_all a3 a10);
                            a9 := List.sort compare !a9
                          done;
                          if List.length !a4 == a5 then
                            !a4
                          else []
                        end
let () =
  let a2 = a14 () in
  let a3 = a15 a2 in
  let a4 = a19 a3 in
  match a4 with
  | [] -> print_endline "cycle"
  | _ -> print_endline (String.concat "\n" a4)
